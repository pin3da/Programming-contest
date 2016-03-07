#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long dp[60][60][2];

long long go(const long long &n, int i, int acc, int top) {
  if (i == -1)
    return acc;

  if (dp[i][acc][top] != -1)
    return dp[i][acc][top];

  long long ans = go(n, i - 1, acc, !((n >> i) & 1LL) && top);
  if (!top || ((n >> i) & 1))
    ans += go(n, i - 1, acc + 1, ((n >> i) & 1LL) && top);

  return dp[i][acc][top] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b) {
    a--;
    memset(dp, -1, sizeof dp);
    long long ans = go(b, 55, 0, 1);
    memset(dp, -1, sizeof dp);
    ans -= go(a, 55, 0, 1);
    cout << ans << endl;
  }
  return 0;
}
