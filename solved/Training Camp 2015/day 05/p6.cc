using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int tar;
int r, c;
int g[555][555];
int dp[555][555];


bool ok(int m) {
  memset(dp,0,sizeof dp);
  dp[0][0] = m;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i && dp[i - 1][j] > 0)
        dp[i][j] = max(0, dp[i - 1][j] + g[i][j]);
      if (j && dp[i][j - 1] > 0)
        dp[i][j] = max(0, max(dp[i][j], dp[i][j - 1] + g[i][j]));
    }
  }

  return dp[r - 1][c - 1] != 0;
}

void solve() {
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> g[i][j];
    }
  }
  int lo = 0, hi = 60000000, mid;

  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (lo + 1 == hi) {
      if (!ok(lo))
        lo = hi;
      break;
    }

    if (ok(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
