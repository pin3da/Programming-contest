package leetcode211

import (
	"testing"

	"github.com/google/go-cmp/cmp"
)

func TestWordDictionary(t *testing.T) {
	tests := []struct {
		name string
		ops  [][]string
		want []bool
	}{
		{
			name: "example from problem statement",
			ops: [][]string{
				{"addWord", "bad"},
				{"addWord", "dad"},
				{"addWord", "mad"},
				{"search", "pad"},
				{"search", "bad"},
				{"search", ".ad"},
				{"search", "..d"},
			},
			want: []bool{false, true, true, true},
		},
		{
			name: "empty and edge cases",
			ops: [][]string{
				{"search", ""},
				{"addWord", "a"},
				{"search", ""},
				{"search", "a"},
				{"search", "."},
				{"addWord", "ab"},
				{"search", "a."},
				{"search", ".b"},
				{"search", ".."},
			},
			want: []bool{false, false, true, true, true, true, true},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			dict := Constructor()
			got := []bool{}
			for _, op := range tt.ops {
				switch op[0] {
				case "addWord":
					dict.AddWord(op[1])
				case "search":
					got = append(got, dict.Search(op[1]))
				}
			}

			if diff := cmp.Diff(tt.want, got); diff != "" {
				t.Errorf("mismatch (-want +got):\n%s", diff)
			}
		})
	}
}
