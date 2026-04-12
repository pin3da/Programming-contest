package main

import (
	"slices"
	"testing"
)

func TestMedianSlidingWindow(t *testing.T) {
	tests := []struct {
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

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := medianSlidingWindow(tt.nums, tt.k)
			if !slices.Equal(got, tt.want) {
				t.Errorf("medianSlidingWindow(%v, %d) = %v, want %v",
					tt.nums, tt.k, got, tt.want)
			}
		})
	}
}
