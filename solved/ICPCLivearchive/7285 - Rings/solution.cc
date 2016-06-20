#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> t(n, vector<int>(m));
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'T') {
          if (i == 0 || i == (n - 1) || j == 0 || (j == m - 1)) {
            t[i][j] = 1;
            tmp.push_back(make_pair(i, j));
          } else
            t[i][j] = -1;
        } else {
          q.push(make_pair(i, j));
        }
      }
    }

    int cool = 0;
    int mmax = 0;
    if (q.empty()) {
      cool = 1;
      for (int i = 0; i < tmp.size(); ++i)
        q.push(tmp[i]);
    }

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      if (t[x][y] == 1 && !cool) {
        for (int i = 0; i < tmp.size(); ++i)
          q.push(tmp[i]);
        cool = true;
      }
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >=0 && nx < n && ny >= 0 && ny < m) {
          if (t[nx][ny] == -1) {
            t[nx][ny] = t[x][y] + 1;
            q.push(make_pair(nx, ny));
            mmax = max(mmax, t[nx][ny]);
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (t[i][j] == 0) {
          if (mmax < 10)
            cout << "..";
          else
            cout << "...";
        } else {
          if (mmax < 10)
            cout << setw(2) << setfill('.') << t[i][j];
          else
            cout << setw(3) << setfill('.') << t[i][j];
        }
      }
      cout << endl;
    }

  }
  return 0;
}

