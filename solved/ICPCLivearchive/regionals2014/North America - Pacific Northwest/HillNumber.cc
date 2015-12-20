using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

string line;

bool check(string &s, int i, int dec) {
  if (s.size() == 1 || i == s.size()) return true;
  if (dec && s[i - 1] < s[i]) return false;
  return check(s, i + 1, dec || s[i - 1] > s[i]);
}

typedef unsigned long long LL;

LL dp[77][3][3][11];

LL go(int i, int top, int dec, int ant) {
  if (i == line.size()) return 1;
  if (dp[i][top][dec][ant] != -1)
    return dp[i][top][dec][ant];
  int mmax = top ? line[i] - '0' : 9;
  LL ans = 0;
  for (int j = 0; j <= mmax; ++j) {
    if (dec && ant < j) continue;
    ans += go(i + 1, top && j == mmax, dec || ant > j, j);
  }
  return dp[i][top][dec][ant] = ans;
}

void solve() {
  cin >> line;
  if (check(line, 1, 0)) {
    // cout << "cool dp" << endl;
    memset(dp, -1, sizeof dp);
    cout << go(0, 1, 0, 0) - 1 << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
  int tc;cin >> tc;
  while (tc--) solve();
  return 0;
}
