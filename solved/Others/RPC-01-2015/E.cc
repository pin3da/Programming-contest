using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n; cin >> n;
  vector<int> nums(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    sum += nums[i];
  }
  vector<vector<long long> > dp(n, vector<long long>(2));

  dp[0][0] = nums[0];
  for (int i = 1; i < n; ++i)
      dp[i][0] =  nums[i] + max(0LL, dp[i - 1][0]);

  dp[0][1] = min(0, nums[0]);
  for (int i = 1; i < n; ++i)
    dp[i][1] = min(0LL, nums[i] + min(0LL, dp[i - 1][1]));

  long long mmin = dp[0][1];
  long long mmax = dp[0][0];
  for (int i = 0; i < n; ++i) {
    mmin = min(mmin, dp[i][1]);
    mmax = max(mmax, dp[i][0]);
  }

  long long ans = max(mmax, sum - mmin);
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
