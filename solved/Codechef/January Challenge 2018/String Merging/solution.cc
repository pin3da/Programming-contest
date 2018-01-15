#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MN = 5001;
const int ML = 27;
const int inf = 2 * MN;


int dp[MN][MN];
string a, b;

string clean(string a) {
  string ans;
  ans.push_back(a[0]);
  for (auto i : a) {
    if (ans.back() != i)
      ans.push_back(i);
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  cin >> a >> b;

  a = clean(a);
  b = clean(b);
  n = a.size();
  m = b.size();

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  cout << n + m - dp[n][m] << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
