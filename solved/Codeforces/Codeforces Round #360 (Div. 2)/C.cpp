// http://codeforces.com/contest/688/problem/C

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int dfs(vector<vector<int>> &g, vector<int> &col, int node, int c) {
  if (col[node] != -1)
    return c == col[node];

  col[node] = c;
  int ok = 1;
  for (auto &to: g[node])
    ok &= dfs(g, col, to, c ^ 1);
  return ok;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> g(n);
    int u, v;
    set<int> s;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--, v--;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
      s.insert(u);
      s.insert(v);
    }

    int ok = true;
    vector<int> color(n, -1);
    for (auto &i: s) {
      if (color[i] == -1) {
        ok &= dfs(g, color, i, 0);
      }
    }

    if (!ok) {
      cout << -1 << endl;
      continue;
    }

    vector<int> l, r;
    for (auto &i : s) {
      if (color[i] == 0) l.emplace_back(i);
      else r.emplace_back(i);
    }
    cout << l.size() << endl;
    for (auto &i: l)
      cout << i + 1 << ' ';
    cout << endl;
    cout << r.size() << endl;
    for (auto &i: r)
      cout << i + 1 << ' ';
    cout << endl;
  }
  return 0;
}
