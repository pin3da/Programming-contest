#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl
#define endl '\n'

struct st {
  int x, y, v;
  st (int a, int b, int c) : x(a), y(b), v(c) {}
  bool operator < (const st & o) const {
    if (v == o.v) {
      if (x == o.x) return y < o.y;
      return x < o.x;
    }
    return v > o.v;
  }
};


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( INPUT.c_str( ), "r", stdin );
  //freopen( OUTPUT.c_str( ), "w", stdout );
#endif // LOCAL

  int n, m;
  while(cin >> m >> n) {
    vector<vector<int>> g(n, vector<int> (m));
    vector<vector<int>> vi(n, vector<int> (m));
    priority_queue<st> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
        if (i == 0 || j == 0 || (j == m - 1) || (i == n - 1)) {
          q.push(st(i, j, g[i][j]));
          vi[i][j] = true;
        }
      }
    }

    long long total = 0;
    while (!q.empty()) {
      st cur = q.top(); q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        if (nx  >= 0 && nx < n && ny >= 0 && ny < m && !vi[nx][ny]) {
          if (g[nx][ny] < cur.v) {
            q.push(st(nx, ny, cur.v));
            total += cur.v - g[nx][ny];
          } else {
            q.push(st(nx, ny, g[nx][ny]));
          }
          vi[nx][ny] = true;
        }
      }
    }
    cout << total << endl;


  }
  return 0;
}
