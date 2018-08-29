package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type edge struct {
	to, cost, id int
}

type graph [][]edge

var path []int

func findPath(g graph, cur, target int, visited []bool) bool {
	if cur == target {
		return true
	}
	if visited[cur] {
		return false
	}
	visited[cur] = true
	for _, e := range g[cur] {
		if findPath(g, e.to, target, visited) {
			path = append(path, e.id)
			return true
		}
	}
	return false
}

var curTime = 0

func findCheapestBridge(g graph, cur, pi, target, forb int, tin, fup, cost []int) (bool, int) {
	tin[cur] = curTime
	fup[cur] = curTime
	curTime++

	can := cur == target
	idBest := -1
	for _, e := range g[cur] {
		if e.id == forb || e.id == pi {
			continue
		}
		if tin[e.to] != 0 {
			fup[cur] = min(fup[cur], tin[e.to])
		} else {
			c, id := findCheapestBridge(g, e.to, e.id, target, forb, tin, fup, cost)
			if id != -1 {
				if idBest == -1 || cost[id] < cost[idBest] {
					idBest = id
				}
			}
			if fup[e.to] == tin[e.to] && c {
				if idBest == -1 || e.cost < cost[idBest] {
					idBest = e.id
				}
			}
			can = can || c

			fup[cur] = min(fup[cur], fup[e.to])
		}
	}

	return can, idBest
}

func main() {
	cin := NewReader()

	n := cin.NextInt()
	m := cin.NextInt()
	s := cin.NextInt() - 1
	t := cin.NextInt() - 1

	g := make(graph, n)
	cost := make([]int, m)
	for i := 0; i < m; i++ {
		u := cin.NextInt() - 1
		v := cin.NextInt() - 1
		c := cin.NextInt()
		g[u] = append(g[u], edge{v, c, i})
		g[v] = append(g[v], edge{u, c, i})
		cost[i] = c
	}

	visited := make([]bool, n)
	path = []int{}

	if !findPath(g, s, t, visited) {
		fmt.Printf("0\n0\n")
		return
	}

	best := -1
	ans := []int{}

	tin := make([]int, n)
	fup := make([]int, n)

	for _, id := range path {
		for i := 0; i < n; i++ {
			tin[i] = 0
			fup[i] = 0
		}

		curTime = 1
		found, bridgeID := findCheapestBridge(g, s, -1, t, id, tin, fup, cost)

		if bridgeID == -1 {
			if !found && (best == -1 || cost[id] < best) {
				best = cost[id]
				ans = []int{id}
			}
		} else {
			if best == -1 || (cost[id]+cost[bridgeID] < best) {
				best = cost[id] + cost[bridgeID]
				ans = []int{id, bridgeID}
			}
		}
	}

	if len(ans) > 0 {
		fmt.Printf("%d\n%d\n", best, len(ans))
		for _, it := range ans {
			fmt.Printf("%d ", it+1)
		}
		fmt.Println()
	} else {
		fmt.Printf("-1\n")
	}
}

// Reader is a fast input for programming competitions
type Reader struct {
	scanner *bufio.Scanner
}

// NewReader ...
func NewReader() *Reader {
	var reader Reader
	reader.scanner = bufio.NewScanner(os.Stdin)
	reader.scanner.Split(bufio.ScanWords)
	return &reader
}

// NextInt ...
func (r *Reader) NextInt() int {
	r.scanner.Scan()
	res, _ := strconv.Atoi(r.scanner.Text())
	return res
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
