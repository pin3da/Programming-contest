#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


bool check(vector<string> &g, int sx, int sy) {
  int n = g.size(), m = g[0].size();

  int h = 0, w = 0;
  for (int i = sx; i < n && g[i][sy] == 'X'; i++) h++;
  for (int i = sy; i < m && g[sx][i] == 'X'; i++) w++;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char target = '.';
      if (i >= sx && i < (sx + h) && j >= sy && j < (sy + w)) target = 'X';
      if (g[i][j] != target) return false;
    }
  }
  return true;
}


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (auto &it : grid) cin >> it;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'X') {
        puts(check(grid, i, j) ? "YES" : "NO");
        return 0;
      }
    }
  }

  puts("NO");
  return 0;
}
