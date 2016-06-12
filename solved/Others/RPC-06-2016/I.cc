#include <bits/stdc++.h>
using namespace std;

void rot(vector<vector<char>> &g) {
  int n = g.size();
  vector<vector<char>> ans(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[j][n - 1 - i] = g[i][j];
    }
  }
  g = ans;
}

void fill(vector<vector<char>> &g,
    vector<vector<char>> &ans, string &line, int &id, int &ok) {
  int n = g.size();
  for (int i = 0; i < n && ok; ++i) {
    for (int j = 0; j < n && ok; ++j) {
      if (g[i][j] == '.') {
        if (id < n * n && ans[i][j] == '$') {
          ans[i][j] = line[id];
          id++;
        } else {
          ok = false;
        }
      }
    }
  }
}

int main() {
  int n;
  while (cin >> n) {
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    string line; cin >> line;
    vector<vector<char>> ans(n, vector<char>(n, '$'));
    int id = 0, ok = true;
    fill(g, ans, line, id, ok);
    rot(g);
    fill(g, ans, line, id, ok);
    rot(g);
    fill(g, ans, line, id, ok);
    rot(g);
    fill(g, ans, line, id, ok);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (ans[i][j] == '$')
          ok = 0;
      }
    }

    if (!ok) {
      cout << "invalid grille" << endl;
      continue;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
