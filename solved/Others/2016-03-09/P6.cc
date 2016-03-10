#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string ori = "NLSO";
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, s;
  while (cin >> n >> m >> s && (n + m + s) ) {
    vector<string> g(n);
    int x, y, dir;
    for (int i = 0; i < n; ++i) {
      cin >> g[i];
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < ori.size(); ++k) {
          if (g[i][j] == ori[k]) {
            x = i;
            y = j;
            dir = k;
          }
        }
      }
    }

    string line;
    cin >> line;
    int ans = 0;
    for (int i = 0; i < line.size(); ++i) {
      char op = line[i];
      if (op == 'F') {
        int nx = x + dx[dir],
            ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#') {
          if (g[nx][ny] == '*') {
            ans++;
          }
          g[nx][ny] = '.';
          x = nx, y = ny;
        }
      }

      if (op == 'D') {
        dir = (dir + 1) % 4;
      }
      if (op == 'E') {
        dir = (dir + 3) % 4;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
