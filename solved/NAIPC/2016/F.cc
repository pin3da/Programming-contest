#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x " = " << (x) << endl

const long long mod = 1000 * 1000 * 1000 + 7;


int n, w, h;
long long dp[111][10101];

long long add(long long x, long long y) {
  x += y;
  if (x >= mod)
    return x - mod;
  return x;
}

long long go(int i, int rem) {
  if (i == w)
    return 1;

  if (dp[i][rem] != -1)
    return dp[i][rem];

  if (rem == 0)
    return dp[i][rem] = 1;

  long long ans = 0;
  for (int j = 0; j <= h; ++j) {
    if (rem - j < 0) continue;
    ans = add(ans, go(i + 1, rem - j));
  }
  return dp[i][rem] = ans;

}

int main() {
  while (cin >> n >> w >> h) {
    memset(dp, -1, sizeof dp);
    long long ans = go(0, n);
    int mmax = min(n, w * h);
    long long m = (mmax / w) + 1;
    ans = (ans - m + mod) % mod;
    cout << ans << endl;
  }
  return 0;
}
