// http://codeforces.com/contest/628/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 300000 + 300;
long long dp[MN][5][3];

long long go(string &line, int i, int acc, int t) {
  if (line.size() == i)
    return acc == 0  && t;
  long long ans = 0;
  if (dp[i][acc][t] != -1)
    return dp[i][acc][t];
  if (t) {
    ans += go(line, i + 1, (acc * 10 + line[i] - '0') % 4, t);
    ans += acc == 0;
  } else {
    ans += go(line, i + 1, (line[i] - '0') % 4, 1);
    ans += go(line, i + 1, 0, 0);
  }
  return dp[i][acc][t] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    memset(dp, -1, sizeof dp);
    cout << go(line, 0, 0, 0) << endl;
  }
  return 0;
}
