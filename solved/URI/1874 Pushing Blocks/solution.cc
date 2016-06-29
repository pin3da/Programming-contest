#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, f;
  while (cin >> n >> m >> f && (n + m + f)) {
    vector<vector<int>> g(n, vector<int>(m));
    for (auto &i : g)
      for (auto &j : i)
        cin >> j;

    int t;
    int x = 0, y = m - 1;
    int r = true;
    for (int i = 0; i < f; ++i) {
      cin >> t;
      if (r) while (g[x][y] != 0) {
        x--;
        if (x < 0) {
          x = n - 1;
          y--;
          if (y < 0) {
            r = 0;
            break;
          }
        }
      }
      if (r) {
        g[x][y] = t;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j) cout << ' ';
        cout << g[i][j];
      }
      cout << endl;
    }

  }
  return 0;
}
