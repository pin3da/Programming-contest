class Solution {
  public:
    int uniqueLetterString(string S) {
      vector<set<int>> frec(30);
      for (int i = 0; i < S.size(); i++) {
        frec[S[i] - 'A'].insert(i);
      }

      long long total = 0;
      const long long mod = 1e9 + 7;
      for (int i = 0; i < S.size(); i++) {
        int p = S[i] - 'A';
        auto it = frec[p].lower_bound(i);
        int left = -1;
        if (it != frec[p].begin()) {
          it--;
          left = *it;
        }

        it = frec[p].lower_bound(i);
        int right = S.size();
        it++;
        if (it != frec[p].end()) {
          right = *it;
        }
        long long partial = (i - left) * (right - i);
        partial = (partial) % mod;
        total = (total + partial) % mod;
      }
      return total;
    }
};
