package leetcode1452

import (
	"testing"

	"github.com/google/go-cmp/cmp"
)

func TestPeopleIndexes(t *testing.T) {
	tests := []struct {
		name              string
		favoriteCompanies [][]string
		want              []int
	}{
		{
			name: "example 1",
			favoriteCompanies: [][]string{
				{"leetcode", "google", "facebook"},
				{"google", "microsoft"},
				{"google", "facebook"},
				{"google"},
				{"amazon"},
			},
			want: []int{0, 1, 4},
		},
		{
			name: "example 2",
			favoriteCompanies: [][]string{
				{"leetcode", "google", "facebook"},
				{"leetcode", "amazon"},
				{"facebook", "google"},
			},
			want: []int{0, 1},
		},
		{
			name:              "single person",
			favoriteCompanies: [][]string{{"amazon"}},
			want:              []int{0},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := peopleIndexes(tt.favoriteCompanies)
			if diff := cmp.Diff(tt.want, got); diff != "" {
				t.Errorf("peopleIndexes() mismatch (-want +got):\n%s", diff)
			}
		})
	}
}
