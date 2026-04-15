package solution

import (
	"testing"
)

func TestMaxPathSum(t *testing.T) {
	tests := []struct {
		name     string
		root     *TreeNode
		expected int
	}{
		{
			name: "Example 1",
			root: &TreeNode{
				Val:   1,
				Left:  &TreeNode{Val: 2},
				Right: &TreeNode{Val: 3},
			},
			expected: 6,
		},
		{
			name: "Example 2",
			root: &TreeNode{
				Val:  -10,
				Left: &TreeNode{Val: 9},
				Right: &TreeNode{
					Val:   20,
					Left:  &TreeNode{Val: 15},
					Right: &TreeNode{Val: 7},
				},
			},
			expected: 42,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := maxPathSum(tt.root); got != tt.expected {
				t.Errorf("maxPathSum() = %v, want %v", got, tt.expected)
			}
		})
	}
}
