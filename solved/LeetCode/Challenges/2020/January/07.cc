class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> freq;
    int i = 0;
    int j = 0;
    int best = 0;
    while (i < s.size() && j < s.size()) {
      while (j < s.size() && freq[s[j]] < 1) {
        freq[s[j]]++;
        j++;
        best = max(best, j - i);
      }
      if (j >= s.size()) {
        break;
      }
      while (i < s.size() && s[i] != s[j]) {
        freq[s[i]]--;
        i++;
      }
      freq[s[i]]--;
      i++;
    }
    return best;
 }
};
