// Chef and Escaping from the Labyrinth
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int inf = 1e9;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct st {
  int x, y, d;
  st(int a, int b, int c) : x(a), y(b), d(c) {}
  bool operator < (const st &o) const {
    if (d == o.d) return make_pair(x, y) < make_pair(o.x, o.y);
    return d > o.d;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m));
  vector<vector<int>> dist(n, vector<int>(m, -1));
  for (auto &it : b) for (auto &i : it) cin >> i;


  set<st> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] > 0) {
        q.insert(st(i, j, b[i][j]));
        dist[i][j] = b[i][j];
      }
    }
  }

  while (!q.empty()) {
    auto cur = *(q.begin()); q.erase(q.begin());

    // if (cur.d < dist[cur.x][cur.y]) continue;

    for (int k = 0; k < 4; k++) {
      int x = cur.x + dx[k], y = cur.y + dy[k];

      if (x >= 0 && x < n && y >= 0 && y < m && b[x][y] != -1) {
        if (dist[x][y] <= (dist[cur.x][cur.y] - 1)) {
          q.erase(st(x, y, dist[x][y]));
          dist[x][y] = dist[cur.x][cur.y] - 1;
          q.insert(st(x, y, dist[x][y]));
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] >= 0) {
        cout << "Y";
      } else {
        if (b[i][j] == -1)
          cout << "B";
        else
          cout << "N";
      }
    }
    cout << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
