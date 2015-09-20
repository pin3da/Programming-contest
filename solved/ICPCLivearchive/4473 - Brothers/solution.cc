using namespace std;
#include <bits/stdc++.h>
#define endl '\n'


int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int N, n, m, k;
  while (cin >> N >> n >> m >> k) {
    if ((N + n + m + k) == 0) break;
    vector<vector<int> > g(n, vector<int>(m)) ;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
      }
    }

    while (k--) {
      vector<vector<int> > g2 = g;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          for (int p = 0; p < 4; ++p) {
            int x = i + dx[p];
            int y = j + dy[p];
            if (x >= 0 && x < n && y >= 0 && y < m) {
              if (g[x][y] == (g[i][j] + 1) % N)
                g2[x][y] = g[i][j];
            }
          }
        }
      }
      swap(g, g2);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j) cout << " ";
        cout << g[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
