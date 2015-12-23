using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#ifndef BMO
#define endl '\n'
#define _io ios_base::sync_with_stdio(false);cin.tie(NULL);
#else
#define _io
#endif

const int MN = 1001;
int dp[MN][MN];
int go(string &s, int i, int j) {
  if (i >= j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int best = go(s, i + 1, j - 1) + (s[i] != s[j]);
  best = min(best, go(s, i + 1, j) + 1);
  best = min(best, go(s, i, j - 1) + 1);
  return dp[i][j] = best;
}

void solve(int n) {
  string line;
  for (int i = 0; i <  n; ++i) {
    cin >> line;
    memset(dp, -1, sizeof dp);
    cout << "Case " << i + 1 << ": ";
    cout << go(line, 0, line.size() - 1) << endl;
  }
}

int main() { _io
  int tc;
  while (cin >> tc) solve(tc);
  return 0;
}
