package main

// trieNodeOpt is a compact trie node using int32 indices instead of pointers.
// Node size: 12 bytes (int32 count + [2]int32 children) vs 24 bytes in the
// pointer-based version, fitting ~2x more nodes per cache line.
type trieNodeOpt struct {
	count    int32
	children [2]int32 // indices into pool; 0 is the null sentinel
}

// trieOpt is a pool-allocated order-statistics multiset backed by a binary trie.
// pool[0] is the null sentinel: count=0, children=[0,0] — always zero-valued.
// pool[1] is the root.
type trieOpt struct {
	pool []trieNodeOpt
	next int32
}

// newTrieOpt allocates a trie sized for n total insertions.
// Each insertion traverses trieDepth levels, creating at most one new node
// per level, so the pool needs at most trieDepth*n + 2 entries.
func newTrieOpt(n int) *trieOpt {
	t := &trieOpt{
		pool: make([]trieNodeOpt, trieDepth*n+2),
		next: 1,
	}
	t.next++ // reserve index 1 as root
	return t
}

func (t *trieOpt) alloc() int32 {
	idx := t.next
	t.next++
	return idx
}

// insert adds one occurrence of x to the multiset.
func (t *trieOpt) insert(x int) {
	val := uint32(x + offset)
	node := int32(1) // root
	for i := trieDepth - 1; i >= 0; i-- {
		bit := (val >> uint(i)) & 1
		if t.pool[node].children[bit] == 0 {
			t.pool[node].children[bit] = t.alloc()
		}
		node = t.pool[node].children[bit]
		t.pool[node].count++
	}
}

// delete removes one occurrence of x from the multiset.
// Precondition: x must be present.
func (t *trieOpt) delete(x int) {
	val := uint32(x + offset)
	node := int32(1) // root
	for i := trieDepth - 1; i >= 0; i-- {
		bit := (val >> uint(i)) & 1
		node = t.pool[node].children[bit]
		t.pool[node].count--
	}
}

// kth returns the k-th smallest element (1-indexed).
// Precondition: 1 <= k <= total number of elements in the multiset.
// pool[0].count == 0 (null sentinel), so the left-child read is always safe
// without a nil check.
func (t *trieOpt) kth(k int32) int {
	node := int32(1) // root
	val := uint32(0)
	for i := trieDepth - 1; i >= 0; i-- {
		leftCount := t.pool[t.pool[node].children[0]].count
		if leftCount >= k {
			node = t.pool[node].children[0]
		} else {
			k -= leftCount
			val |= 1 << uint(i)
			node = t.pool[node].children[1]
		}
	}
	return int(val) - offset
}

func medianSlidingWindowOpt(nums []int, k int) []float64 {
	t := newTrieOpt(len(nums))
	result := make([]float64, 0, len(nums)-k+1)

	// Precompute ranks once — avoids k%2 branch inside the hot loop.
	// For odd k: lo == hi == (k+1)/2, so kth is called once.
	// For even k: lo = k/2, hi = k/2+1.
	lo, hi := int32((k+1)/2), int32((k+2)/2)

	for i, x := range nums {
		t.insert(x)
		if i >= k {
			t.delete(nums[i-k])
		}
		if i >= k-1 {
			if lo == hi {
				result = append(result, float64(t.kth(lo)))
			} else {
				result = append(result, (float64(t.kth(lo))+float64(t.kth(hi)))/2.0)
			}
		}
	}
	return result
}
