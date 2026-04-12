package main

const (
	trieDepth = 32
	offset    = 1 << 31
)

// trieNode is a node in the binary trie.
type trieNode struct {
	count    int
	children [2]*trieNode
}

// trie is an order-statistics multiset backed by a binary trie.
// Values are stored offset by 1<<31 so all int32 values map to
// non-negative indices in [0, 2^32).
type trie struct {
	root *trieNode
}

func newTrie() *trie {
	return &trie{root: &trieNode{}}
}

// insert adds one occurrence of x to the multiset.
func (t *trie) insert(x int) {
	x += offset
	node := t.root
	for i := trieDepth - 1; i >= 0; i-- {
		bit := (x >> i) & 1
		if node.children[bit] == nil {
			node.children[bit] = &trieNode{}
		}
		node = node.children[bit]
		node.count++
	}
}

// delete removes one occurrence of x from the multiset.
// Precondition: x must be present.
func (t *trie) delete(x int) {
	x += offset
	node := t.root
	for i := trieDepth - 1; i >= 0; i-- {
		bit := (x >> i) & 1
		node = node.children[bit]
		node.count--
	}
}

// kth returns the k-th smallest element (1-indexed).
// Precondition: 1 <= k <= total number of elements in the multiset.
func (t *trie) kth(k int) int {
	node := t.root
	val := 0
	for i := trieDepth - 1; i >= 0; i-- {
		leftCount := 0
		if node.children[0] != nil {
			leftCount = node.children[0].count
		}
		if leftCount >= k {
			node = node.children[0]
		} else {
			k -= leftCount
			val |= 1 << i
			node = node.children[1]
		}
	}
	return val - offset
}

func medianSlidingWindow(nums []int, k int) []float64 {
	t := newTrie()
	result := make([]float64, 0, len(nums)-k+1)

	for i, x := range nums {
		t.insert(x)
		if i >= k {
			t.delete(nums[i-k])
		}
		if i >= k-1 {
			if k%2 == 1 {
				result = append(result, float64(t.kth(k/2+1)))
			} else {
				// Cast to float64 before adding to avoid int overflow.
				result = append(result, (float64(t.kth(k/2))+float64(t.kth(k/2+1)))/2.0)
			}
		}
	}
	return result
}
