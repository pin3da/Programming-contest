#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1e9 + 7;

int K;
const int MN = 1001;
int color[MN][MN];
long long dp[MN][MN];
int curcol;

long long go(int n, int k) {
  if (n == 0) return k == 0;
  if (color[n][k] == curcol) return dp[n][k];
  color[n][k] = curcol;
  long long ans = go(n - 1, k) * (K - k) + go(n - 1, k - 1) * k;
  ans %= mod;
  return dp[n][k] = ans;
}

void solve() {
  curcol++;
  int n;
  scanf("%d%d", &n, &K);
  if (n < K) {
    puts("0");
    return;
  }
  printf("%d\n", (int)go(n, K));
}

int main() {
#ifndef LOCAL
#define endl '\n'
  freopen("galactic.in", "r", stdin);
#endif

  curcol = 1;
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}
