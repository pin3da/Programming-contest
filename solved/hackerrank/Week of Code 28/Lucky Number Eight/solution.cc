#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1e9 + 7;

const int MN = 212345;
long long dp[MN][10][3];

long long go(string &s, int pos, int cur, int taken) {
  if (pos == (int)s.size())
    return (cur == 0) && taken;

  if (dp[pos][cur][taken] != -1)
    return dp[pos][cur][taken];

  long long ans = go(s, pos + 1, cur, taken);

  ans = (ans
        + go(s, pos + 1, (cur * 10 + (s[pos] - '0')) % 8, true)
        ) % mod;

  return dp[pos][cur][taken] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  string s; cin >> s;
  memset(dp, -1, sizeof dp);
  cout << go(s, 0, 0, 0) << endl;
  return 0;
}
