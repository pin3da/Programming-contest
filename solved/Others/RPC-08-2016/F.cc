#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 20;
int MC;

int col[MN];

typedef vector<vector<int> > graph;

bool check(graph &g, int node) {
  if (node == g.size()) return true;

  for (int c = 0; c < MC; ++c) {
    col[node] = c;
    int ok = true;
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i];
      if (col[to] != -1 && (col[node] == col[to]))
        ok = false;
    }
    if (!ok) {
      col[node] = -1;
      continue;
    }
    if (check(g, node + 1)) return true;
    for (int i = node + 1; i < g.size(); ++i)
      col[i] = -1;
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  MC = 4;  memset(col, -1, sizeof col);
  if (!check(g, 0)) {
    cout << "many" << endl;
  } else {
    MC = 3;  memset(col, -1, sizeof col);
    if (!check(g, 0)) {
      cout << 4 << endl;
    } else {
      MC = 2;  memset(col, -1, sizeof col);
      if (!check(g, 0)) {
        cout << 3 << endl;
      } else {
        MC = 1;  memset(col, -1, sizeof col);
        if (!check(g, 0))
          cout << 2 << endl;
        else
          cout << 1 << endl;
      }
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
