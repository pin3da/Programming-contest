// http://codeforces.com/contest/339/problem/C

#include <bits/stdc++.h>

using namespace std;

char a[12];

int dp[22][1234][12];

bool go(int cur, int m, int last) {
  if (m == 0) return true;
  if (dp[cur + 10][m][last + 1] != -1)
    return dp[cur + 10][m][last + 1];
  int cu = abs(cur);
  for (int i = cu + 1; i <= 10; ++i) {
    if (i != last && a[i - 1] == '1') {
      if (go(i - cu, m - 1, i))
        return dp[cur + 10][m][last + 1] = 1;
    }
  }
  return dp[cur + 10][m][last + 1] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for (int i = 0; i < 10; ++i)
    cin >> a[i];
  memset(dp, -1, sizeof dp);
  int m; cin >> m;
  if (go(0, m, -1)) {
    cout << "YES" << endl;
    int cur = 0, last = -1;
    for (int i = 0; i < m; ++i) {
      if (i) cout << ' ';
      int cu = abs(cur);
      for (int j = cu + 1; j <= 10; ++j) {
        if (j != last && a[j - 1] == '1') {
          if (go(j - cu, m - i - 1, j)) {
            cout << j;
            cur = j - cu;
            last = j;
            break;
          }
        }
      }
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
