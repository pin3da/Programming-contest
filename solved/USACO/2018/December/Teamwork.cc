#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> skill(n);
  for (auto &it : skill) cin >> it;

  vector<long long> dp(n + 1);

  for (int i = n - 1; i >= 0; i--) {
    int curMax = skill[i];
    for (int j = 0; j < k && (i + j) < n; j++) {
      curMax = max(curMax, skill[i + j]);
      dp[i] = max(dp[i], curMax * (j + 1) + dp[i + j + 1]);
    }
  }

  cout << dp[0] << endl;
  return 0;
}
