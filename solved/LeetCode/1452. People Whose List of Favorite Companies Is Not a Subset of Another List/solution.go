package leetcode1452

import "sort"

func peopleIndexes(favoriteCompanies [][]string) []int {
	for i := range favoriteCompanies {
		sort.Strings(favoriteCompanies[i])
	}
	result := []int{}
	for i := range favoriteCompanies {
		subset := false
		for j := range favoriteCompanies {
			if i != j && isSubset(favoriteCompanies[i], favoriteCompanies[j]) {
				subset = true
				break
			}
		}
		if !subset {
			result = append(result, i)
		}
	}
	return result
}

// isSubset reports whether a is a subset of b. Both slices must be sorted.
func isSubset(a, b []string) bool {
	j := 0
	for i := range a {
		for j < len(b) && b[j] < a[i] {
			j++
		}
		if j >= len(b) || b[j] != a[i] {
			return false
		}
		j++
	}
	return true
}
