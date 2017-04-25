// http://codeforces.com/contest/707/problem/A

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    char g[n][m];
    int colr = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'C' || g[i][j] == 'M' || g[i][j] == 'Y')
          colr = true;
      }
    }
    puts(colr ? "#Color" : "#Black&White");
  }

  return 0;
}
