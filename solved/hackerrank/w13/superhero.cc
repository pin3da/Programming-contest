#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl;

typedef pair<int, int> enemy;

int n, m;
vector<vector<enemy> > p;

int dp[111][1001];


void solve() {
  cin >> n >> m;

  p = vector<vector<enemy> > (n, vector<enemy> (m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> p[i][j].first;


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j< m; ++j)
      cin >> p[i][j].second;
  }


  memset(dp, 0, sizeof dp);
  for (int c = 0; c < n; ++c) {
    for (int need = 1; need < 1001; ++need) {
      int best = numeric_limits<int>::max();
      for (int i = 0; i < m; i++) {
        int next = (c == 0) ? p[c][i].first : dp[c - 1][p[c][i].first];
        best = min(best, next + max(0, need - p[c][i].second));
      }
      dp[c][need] = best;
    }
  }


  int best = 2222;
  for (int i = 0; i < m; i++)
    best = min(best, p[n - 1][i].first);

  if (n == 1)
    cout << best << endl;
  else
    cout << dp[n - 2][best] << endl;

}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();

  return 0;
}
