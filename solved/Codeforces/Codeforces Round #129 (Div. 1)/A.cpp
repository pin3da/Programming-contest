// http://codeforces.com/contest/204/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string to_st(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

long long dp[20][3][10][3];

long long go(string &cur, int i, int top, int f, int first) {
  int mmax = top ? cur[i] - '0' : 9;
  if (i == (cur.size() - 1)) {
    if (!first) return 0;
    return (f <= mmax);
  }

  if (dp[i][top][f][first] != -1) return dp[i][top][f][first];

  long long ans = 0;
  for (int k = 0; k <= mmax; ++k) {
    ans += go(cur, i + 1, top && (k == mmax), (first) ? f : k, first || (k != 0));
  }
  return dp[i][top][f][first] = ans;
}

long long f(long long x) {
  if (x < 10) return x + 1;
  memset(dp, -1, sizeof dp);
  string a = to_st(x);
  return go(a, 0, true, 0, 0) + 10;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long l, r;
  while (cin >> l >> r) {
    l--;
    long long ans = f(r);
    ans -= f(l);
    cout << ans << endl;
  }
  return 0;
}
