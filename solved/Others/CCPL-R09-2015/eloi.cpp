using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const long long mod = 9999959999;

const int MN = 2552;
long long dp[MN][MN];

long long go(int n, int m) {
  if (n == 0)
    return  (m + 1) % mod;

  if (dp[n][m] != -1)
    return dp[n][m];
  long long ans = 1 % mod;
  if (n > 0)
    ans = (ans + go(n - 1, m + 1)) % mod;
  if (m > 0)
    ans = (ans + go(n, m - 1)) % mod;
  return dp[n][m] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  memset(dp, -1, sizeof dp);
  while (cin >> n >> m && (n + m)) {
    cout << go(n, m) << endl;
  }
  return 0;
}
