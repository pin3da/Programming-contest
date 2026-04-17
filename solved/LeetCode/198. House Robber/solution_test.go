package solution

import "testing"

func TestRob(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want int
	}{
		{"Example 1", []int{1, 2, 3, 1}, 4},
		{"Example 2", []int{2, 7, 9, 3, 1}, 12},
		{"Single house", []int{5}, 5},
		{"Two houses", []int{2, 1}, 2},
		{"All equal", []int{4, 4, 4, 4}, 8},
		{"Empty", []int{}, 0},
		{"Example 3", []int{2, 1, 1, 2}, 4},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := rob(tt.nums); got != tt.want {
				t.Errorf("rob(%v) = %d, want %d", tt.nums, got, tt.want)
			}
		})
	}
}
