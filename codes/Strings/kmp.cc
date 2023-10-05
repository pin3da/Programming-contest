vector<int> kmp(string& s) {
	vector<int> next;
	int j;
	j = next[1] = 0;
	for (int i = 2; s[i]; ++i) {
		while (j > 0 && s[j + 1] != s[i])
			j = next[j];
		if (s[j + 1] == s[i])
			++j;
		next[i] = j;
	}
	return next;
}