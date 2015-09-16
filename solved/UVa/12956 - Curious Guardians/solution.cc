using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

long long mod = 1000000007;
const int MN = 101;
long long comb[MN][MN];

int K;
long long dp[MN][MN];
long long go(int n, int k) {
  if (n <= 1) return 1;

  if (k == 1) {
    return (n * go(n - 1, K - 1)) % mod;
  }

  if (k == 0) return 0;

  if (dp[n][k] != -1)
    return dp[n][k];

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long t = (comb[n - 1][i - 1] * i) % mod;
    t = (t  * go(n - i, k - 1)) % mod;
    t = (t  * go(i - 1, K - 1)) % mod;
    ans = (ans + t) % mod;
  }

  return dp[n][k] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  for (int i = 0; i < MN; ++i)
    comb[i][0] = comb[i][i] = 1;

  for (int i = 2; i < MN; ++i)
    for (int j = 1; j < MN; ++j)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;

  while (cin >> n >> K) {
    memset(dp, -1, sizeof dp);
    cout << go(n - 1, K) << endl;
  }
  return 0;
}
