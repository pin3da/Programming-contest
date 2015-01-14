using namespace std;
#include <bits/stdc++.h>


const long long mod = 1000000007;

const int MN = 100011;

int main() {

  int n;cin >> n;
  vector <int> nums(n, -1);
  string t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t != "?")
      nums[i] = atoi(t.c_str());
  }

  long long dp[5][MN];
  memset(dp, 0, sizeof dp);

  int cur = 0, next = 1;
  if (nums[n - 1] == -1) {
    for (int i = 1; i < MN; i++)
      dp[cur][i] = 1;
  } else {
    dp[cur][nums[n - 1]] = 1;
  }

  for (int i = 1; i < MN; ++i)
    dp[cur][i] = (dp[cur][i] + dp[cur][i -1]) % mod;


  for (int i = n - 2; i >= 0; --i) {
    memset(dp[next], 0, sizeof dp[next]);
    for (int j = (i != 0); j < i + 1; ++j) {
      if (nums[i] != -1)
        if (j != nums[i])
          continue;
      dp[next][j] = dp[cur][j + 1];
    }

    for (int j = 1; j < MN; ++j)
      dp[next][j] = (dp[next][j] + dp[next][j - 1]) % mod;


    swap(next, cur);
  }

  cout << dp[cur][0] % mod << endl;


  return 0;
}
