#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1000 + 10 + 1;
int g[MN][MN];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, -1, 1, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
      }
    }

    int peak = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {

        int cur = 0;
        for (int k = 0; k < 8; ++k) {
          int nx = i + dx[k],
              ny = j + dy[k];

          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (g[nx][ny] >= g[i][j]) cur++;
          }
        }
        if (cur == 0) {
          cout << i + 1 << ' ' << j + 1 << endl;
          peak = true;
        }
      }
    }
    if (!peak)
      cout << -1 << endl;
    cout << endl;
  }
  return 0;
}
