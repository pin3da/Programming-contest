#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct pos {
  int x, y, d;
  bool operator < (const pos &o) const {
    if (x == o.x) {
      if (y == o.y) return d < o.d;
      return y < o.y;
    }
    return x < o.x;
  }
};

// U, R, D, L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));

  pos start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] != '.' && g[i][j] != '*') {
        int k = 0;
        while (g[i][j] != "URDL"[k++]);
        k--;
        start = {i, j, k};
        g[i][j] = '.';
      }
    }
  }

  set<pair<int, int>> ans;
  set<pos> seen;

  deque<pos> q;
  q.push_back(start);
  seen.insert(start);

  while (!q.empty()) {
    pos cur = q.front(); q.pop_front();
    ans.insert({cur.x, cur.y});

    int nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '*') {
      pos nxt = {nx, ny, cur.d};
      if (seen.count(nxt) == 0) {
        seen.insert(nxt);
        q.push_back(nxt);
      }
    } else {
      cur.d = (cur.d + 1) % 4;
      if (seen.count(cur) == 0) {
        seen.insert(cur);
        q.push_back(cur);
      }
    }
  }

  cout << ans.size() << endl;

  return 0;
}
