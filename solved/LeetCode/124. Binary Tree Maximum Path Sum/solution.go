package solution

import (
	"math"
)

// TreeNode defines a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// edge represents a directed edge in the tree to be used as a memoization key.
type edge struct {
	node *TreeNode
	from *TreeNode
}

// This implementation is O(N) in both runtime and memory because it memoizes results
// for each directed edge, ensuring each is computed exactly once.


func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}

	s := &state{
		parents: make(map[*TreeNode]*TreeNode),
		memo:    make(map[edge]int),
		ans:     math.MinInt,
	}

	s.buildParents(root, nil)
	s.computeAll(root)

	return s.ans
}

type state struct {
	parents map[*TreeNode]*TreeNode
	memo    map[edge]int
	ans     int
}

func (s *state) buildParents(u, p *TreeNode) {
	if u == nil {
		return
	}
	s.parents[u] = p
	s.buildParents(u.Left, u)
	s.buildParents(u.Right, u)
}

// getPath returns the maximum path sum starting at node 'u' and NOT extending towards 'from'.
func (s *state) getPath(u, from *TreeNode) int {
	if u == nil {
		return 0
	}

	key := edge{u, from}
	if val, ok := s.memo[key]; ok {
		return val
	}

	bestChild := 0
	for _, v := range s.getNeighbors(u) {
		if v != from {
			bestChild = max(bestChild, s.getPath(v, u))
		}
	}

	res := u.Val + bestChild
	s.memo[key] = res
	return res
}

func (s *state) computeAll(u *TreeNode) {
	if u == nil {
		return
	}

	first, second := 0, 0
	for _, v := range s.getNeighbors(u) {
		val := s.getPath(v, u)
		if val > first {
			second, first = first, val
		} else if val > second {
			second = val
		}
	}

	s.ans = max(s.ans, u.Val+first+second)

	s.computeAll(u.Left)
	s.computeAll(u.Right)
}

func (s *state) getNeighbors(u *TreeNode) []*TreeNode {
	neighbors := make([]*TreeNode, 0, 3)
	if u.Left != nil {
		neighbors = append(neighbors, u.Left)
	}
	if u.Right != nil {
		neighbors = append(neighbors, u.Right)
	}
	if p := s.parents[u]; p != nil {
		neighbors = append(neighbors, p)
	}
	return neighbors
}
