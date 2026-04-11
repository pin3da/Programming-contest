func mostCommonWord(paragraph string, bannedWords []string) string {
	freq := map[string]int{}
	banned := map[string]bool{}

	for _, v := range bannedWords {
		banned[v] = true
	}
	words := strings.FieldsFunc(paragraph, func(r rune) bool {
		return !unicode.IsLetter(r)
	})

	for _, w := range words {
		w = strings.ToLower(w)
		if !banned[w] {
			freq[w]++
		}
	}

	maxKey, maxVal := "", 0
	for k, v := range freq {
		if v > maxVal {
			maxVal = v
			maxKey = k
		}
	}
	return maxKey
}
