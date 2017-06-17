#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

pair<int, int> find_max(vector<vector<int>> &g) {
  int best = -1;
  int n = g.size();
  int m = g[0].size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      best = max(best, g[i][j]);
    }
  }
  if (best <= 0) return {-1, -1};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (best == g[i][j])
        return {i, j};
    }
  }
  return {-1, -1};
}

bool non_zero_row(vector<vector<int>> &g, int row) {
  int m = g[0].size();
  for (int i = 0; i < m; ++i) {
    if (g[row][i] == 0) return false;
  }
  return true;
}

bool non_zero_col(vector<vector<int>> &g, int col) {
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    if (g[i][col] == 0) return false;
  }
  return true;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m; cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  vector<pair<int, int>> ans;
  int ok = true;
  while (true) {
    pair<int, int> cur = find_max(g);
    if (cur.first == -1) break;
    int row = non_zero_row(g, cur.first);
    int col = non_zero_col(g, cur.second);
    if (col && row) {
      if (n < m) {
        for (int i = 0; i < m; ++i)
          g[cur.first][i]--;
        ans.emplace_back(0, cur.first);
      } else {
        for (int i = 0; i < n; ++i)
          g[i][cur.second]--;
        ans.emplace_back(1, cur.second);
      }
    } else if (row) {
      for (int i = 0; i < m; ++i)
        g[cur.first][i]--;
      ans.emplace_back(0, cur.first);
    } else if (col) {
      for (int i = 0; i < n; ++i)
        g[i][cur.second]--;
      ans.emplace_back(1, cur.second);
    } else {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << ans.size() << endl;
    for (auto it : ans) {
      if (it.first) cout << "col ";
      else cout << "row ";
      cout << it.second + 1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
