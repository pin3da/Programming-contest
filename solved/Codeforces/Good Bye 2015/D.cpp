// http://codeforces.com/contest/611/problem/D

using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

const int MN = 5005;
long long dp[MN][MN];
long long mod = 1000000000 + 7;

int lcp[MN][MN];

void fill_lcp(string &s) {
  int n = s.size();
  for (int i = n; i >= 0; i--) {
    for (int j = n; j >= 0; j--) {
      if (i == n || j == n) lcp[i][j] = 0; else
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
      else lcp[i][j] = 0;
    }
  }
}

bool check_greater(string &line, int s, int i, int delta) {
  int t = lcp[s][i];
  if (t >= delta) return false;
  else return line[s + t] < line[i + t];
}

long long go(string &line, int i, int s) {
  if (i == line.size()) return 1;
  if (i > line.size()) return 0;

  if (dp[i][s] != -1) return dp[i][s];
  if (line[i] == '0') return go(line, i + 1, s);

  int delta = i - s + 1;
  long long ans = 0;
  if (check_greater(line, s, i, delta - 1))
    ans = (ans + go(line, i + delta - 1, i)) % mod;
  else
   ans = (ans + go(line, i + delta, i)) % mod;
  ans = (ans + go(line, i + 1, s)) % mod;
  return dp[i][s] = ans;
}

void solve() {
  string line;
  cin >> line;
  long long ans = 0;
  fill_lcp(line);
  memset(dp, -1, sizeof dp);
  ans += go(line, 1, 0);
  cout << ans % mod << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve();
  }
  return 0;
}
