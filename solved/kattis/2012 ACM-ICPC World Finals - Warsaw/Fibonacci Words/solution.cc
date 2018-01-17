#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

vector<int> comp_border(const string &pattern) {
  int m = pattern.size();
  vector<int> border(m);
  border[0] = 0;
  for (int i = 1; i < m; i++) {
    border[i] = border[i - 1];
    while (border[i] > 0 and pattern[i] != pattern[border[i]]) {
      border[i] = border[border[i] - 1];
    }
    if (pattern[i] == pattern[border[i]]) border[i]++;
  }
  return border;
}


int matches(vector<int> &border, const string &pattern, const string &text) {
  int n = text.size();
  int m = border.size();
  int seen = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    while (seen > 0 and text[i] != pattern[seen]) {
      seen = border[seen - 1];
    }
    if (text[i] == pattern[seen]) seen++;

    if (seen == m) {
      // printf("pattern occurs from %d to %d\n", i - m + 1, i);
      ans++;
      seen = border[m - 1];
    }
  }
  return ans;
}

const int MN = 30;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  vector<string> fib;
  fib.push_back("0");
  fib.push_back("1");
  while (fib.size() < MN) {
    fib.push_back(fib.back());
    int len = fib.size();
    for (auto i : fib[len - 3])
      fib[len - 1].push_back(i);
  }

  int tc_id = 0;
  int n;
  string pattern;
  while (cin >> n >> pattern) {

    vector<int> border = comp_border(pattern);

    cout << "Case " << (++tc_id) << ": ";
    if (n < int(fib.size())) {
      if (pattern.size() > fib[n].size())
        cout << 0 << endl;
      else
        cout << matches(border, pattern, fib[n]) << endl;
    } else {
      vector<long long> dp(n + 10);
      dp[MN - 3] = matches(border, pattern, fib[MN - 3]);
      dp[MN - 2] = matches(border, pattern, fib[MN - 2]);
      int start1 = fib[MN - 2].size() - pattern.size() + 1;
      int start2 = fib[MN - 3].size() - pattern.size() + 1;

      string tx1 = fib[MN - 1].substr(start1, 2 * pattern.size() - 2);
      string tx2 = fib[MN - 1].substr(start2, 2 * pattern.size() - 2);

      long long m1 = matches(border, pattern, tx1);
      long long m2 = matches(border, pattern, tx2);

      for (int i = MN - 1; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + m1;
        swap(m1, m2);
      }

      cout << dp[n] << endl;
    }
  }
  return 0;
}
