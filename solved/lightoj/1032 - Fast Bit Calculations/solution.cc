using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


long long dp[33][3][33][3];

int n;
long long go(const int &mask, int i, bool prev, int cur, bool top) {
  if (i < 0)
    return cur;

  if (dp[i][prev][cur][top] != -1)
    return dp[i][prev][cur][top];

  long long ans = go(mask, i - 1, 0, cur, top && !((mask >> i) & 1));

  if (!top || (top && ((mask >> i) & 1)))
    ans += go(mask, i - 1, 1, cur + (prev == 1), top && ((mask >> i) & 1));

  return dp[i][prev][cur][top] = ans;

}

void solve() {
  int k;
  cin >> k;
  n = 0;
  for (int i = 0; i < 32; ++i)
    if ((k >> i) & 1)
      n = i;

  memset(dp, -1, sizeof dp);
  printf("%lld\n", go(k, n, 0, 0, 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
