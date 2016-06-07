#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int K;
const int MN = 111;

bool dp[MN][MN * (MN - 1) / 2];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    K = m;
    vector<int> d(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--;v--;
      d[u]++;
      d[v]++;
    }

    memset(dp, 0, sizeof dp);

    dp[n][K] = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int k = 0; k <= K; ++k) {
        dp[i][k] = dp[i + 1][k];
        if (k + d[i] <= K)
          dp[i][k] |= dp[i + 1][k + d[i]];
      }
    }

    if (dp[0][0]) {
      cout << "S" << endl;
    } else
      cout << "N" << endl;
  }

  return 0;
}
