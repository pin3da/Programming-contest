// http://codeforces.com/contest/480/problem/C

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long long lint;

int n, b;
const lint mod = 1000000007;

const int MN = 5005;
long long dp[MN][MN];

lint get(int k, int a, int b) {
  b = min(b, n);
  lint ans = dp[k][b];
  if (a > 1)
    ans -= dp[k][a - 1];
  return (ans + mod) % mod;
}

int main() { ___
  int a, K;
  cin >> n >> a >> b >> K;


  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i)
    dp[0][i] = i;



  for (int k = 1; k <= K; ++k) {
    for (int x = 1; x <= n; ++x) {
      int len = fabs(x - b) - 1;
      if (x == b) {
        if (x > 1)
          dp[k][x] = (dp[k][x] + dp[k][x - 1]) % mod;
        continue;
      }
      dp[k][x] = (get(k - 1, x - len, x + len) - get(k - 1, x, x)) % mod;
      //cout << "k : " << k << " - x : " << x << " = " << dp[k][x] << endl;
      if (x > 1)
        dp[k][x] = (dp[k][x] + dp[k][x - 1]) % mod;
    }
  }

  cout << get(K, a, a) << endl;

  return 0;
}