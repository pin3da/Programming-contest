#include <bits/stdc++.h>

using namespace std;

const int MN = 1123;
int dp[MN];

int go(vector<vector<int>> &pos, int cur) {
  if (dp[cur] != -1) return dp[cur];

  int ans = 1;
  for (int i = 0; i < (int)pos[0].size(); i++) {
    if (cur == i) continue;
    int after = true;
    for (int j = 0; j < (int) pos.size(); j++) {
      after &= (pos[j][cur] < pos[j][i]);
    }
    if (after)
      ans = max(ans, go(pos, i) + 1);
  }
  return dp[cur] = ans;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> pos(k, vector<int> (n));

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      int t; cin >> t; t--;
      pos[i][t] = j;
    }
  }

  int best = 1;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    best = max(best, go(pos, i));
  }

  cout << best << endl;

  return 0;
}
