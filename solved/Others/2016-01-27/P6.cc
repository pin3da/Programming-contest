#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1005;
long long dp[MN][MN];

const long long mod = 1000000007;

long long go(int b, int g) {
  if (g <= 0)
    return 0;
  if (b == 1)
    return g == 1;

  if (dp[b][g] == -1)
    dp[b][g] = ((g * go(b - 1, g)) % mod + (g * go(b - 1, g - 1)) % mod) % mod;
  return dp[b][g];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int b, g;
  memset(dp, -1, sizeof dp);
  while (cin >> b >> g && (b + g)) {
    cout << go(b, g) << endl;
  }
  return 0;
}
