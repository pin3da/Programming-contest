#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int dp[5][501][501];

int fill_dp(vector<int> &a, int K) {

  memset(dp, 0, sizeof dp);
  dp[1][0][0] = true;

  int s = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    for (int k = 0; k <= K; ++k) {
      for (int j = 0; j <= k; ++j) {
        int ans = false;
        if (k >= a[i]) {
          ans |= dp[s ^ 1][j][k - a[i]];
          if (j >= a[i])
            ans |= dp[s ^ 1][j - a[i]][k - a[i]];
        }
        ans |= dp[s ^ 1][j][k];
        dp[s][j][k] = ans;
      }
    }
    s ^= 1;
  }
  return s ^ 1;
}

bool go(vector<int> &a, int i, int t, int k) {
  if (t < 0 || k < 0) return false;
  if (i == a.size()) {
    return k == 0 && t == 0;
  }

  int op1 = go(a, i + 1, t, k - a[i]) || go(a, i + 1, t - a[i], k - a[i]);
  int op2 = go(a, i + 1, t, k);
  return op1 || op2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    vector<int> ans;
    for (auto &i : a) cin >> i;
    int s = fill_dp(a, k);
    for (int i = 0; i <= k; ++i)
      if (dp[s][i][k])
        ans.emplace_back(i);

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
