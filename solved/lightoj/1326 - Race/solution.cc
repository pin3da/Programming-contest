using namespace std;
#include <bits/stdc++.h>

const int mod = 10056;
const int MN = 1234;
int bc[MN][MN];
int dp[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  for (int i = 0; i < MN; ++i)
    bc[i][0] = bc[i][i] = 1;

  for (int i = 2; i < MN; ++i)
    for (int j = 1; j < i; ++j)
      bc[i][j] = (bc[i - 1][j] + bc[i - 1][j - 1] ) % mod;


  dp[0] = dp[1] = 1;

  for (int i = 2; i < MN; ++i) {
    dp[i] = 0;
    for (int j = 1; j <= i; ++j)
      dp[i] = (dp[i] + (dp[i - j] * bc[i][j]) % mod) % mod;
  }

  int tc, n;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cin >> n;
    printf("Case %d: %d\n", i + 1, dp[n]);
  }
  return 0;
}
