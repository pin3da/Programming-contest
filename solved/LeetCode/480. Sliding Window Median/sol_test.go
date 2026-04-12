package main

import (
	"math/rand/v2"
	"slices"
	"testing"
)

var testCases = []struct {
	name string
	nums []int
	k    int
	want []float64
}{
	{
		name: "example1_odd_k",
		nums: []int{1, 3, -1, -3, 5, 3, 6, 7},
		k:    3,
		want: []float64{1, -1, -1, 3, 5, 6},
	},
	{
		name: "example2_even_k",
		nums: []int{1, 2, 3, 4, 2, 3, 1, 4, 2},
		k:    3,
		want: []float64{2, 3, 3, 3, 2, 3, 2},
	},
	{
		name: "k_equals_1",
		nums: []int{4, 1, 7, 2},
		k:    1,
		want: []float64{4, 1, 7, 2},
	},
	{
		name: "k_equals_len_even",
		nums: []int{1, 2},
		k:    2,
		want: []float64{1.5},
	},
	{
		name: "negative_numbers",
		nums: []int{-5, -3, -1, -2, -4},
		k:    3,
		want: []float64{-3, -2, -2},
	},
}

func TestMedianSlidingWindow(t *testing.T) {
	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			got := medianSlidingWindow(tt.nums, tt.k)
			if !slices.Equal(got, tt.want) {
				t.Errorf("medianSlidingWindow(%v, %d) = %v, want %v",
					tt.nums, tt.k, got, tt.want)
			}
		})
	}
}

func TestMedianSlidingWindowOpt(t *testing.T) {
	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			got := medianSlidingWindowOpt(tt.nums, tt.k)
			if !slices.Equal(got, tt.want) {
				t.Errorf("medianSlidingWindowOpt(%v, %d) = %v, want %v",
					tt.nums, tt.k, got, tt.want)
			}
		})
	}
}

// makeBenchInput generates n random int32 values.
func makeBenchInput(n int) []int {
	nums := make([]int, n)
	for i := range nums {
		// Full int32 range including negatives.
		nums[i] = int(int32(rand.Uint32()))
	}
	return nums
}

func BenchmarkMedianSlidingWindow(b *testing.B) {
	for _, bc := range []struct {
		name string
		n, k int
	}{
		{"n=100000_k=100_odd", 100000, 101},
		{"n=100000_k=100_even", 100000, 100},
		{"n=100000_k=1000", 100000, 1000},
	} {
		nums := makeBenchInput(bc.n)
		b.Run(bc.name, func(b *testing.B) {
			for range b.N {
				medianSlidingWindow(nums, bc.k)
			}
		})
	}
}

func BenchmarkMedianSlidingWindowOpt(b *testing.B) {
	for _, bc := range []struct {
		name string
		n, k int
	}{
		{"n=100000_k=100_odd", 100000, 101},
		{"n=100000_k=100_even", 100000, 100},
		{"n=100000_k=1000", 100000, 1000},
	} {
		nums := makeBenchInput(bc.n)
		b.Run(bc.name, func(b *testing.B) {
			for range b.N {
				medianSlidingWindowOpt(nums, bc.k)
			}
		})
	}
}
