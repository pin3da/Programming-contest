// http://codeforces.com/contest/219/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > graph;

const int MN = 2e5 + 100;


int fix_down[MN];
int fix_up[MN];
int cur_path[MN];

int go(graph &g, graph &inv, int node, int pi, int c, int dep) {

  fix_down[node] = 0;
  fix_up[node] = dep - c;
  cur_path[node] = c;
  for (int i = 0; i < (int)g[node].size(); ++i) {
    int to = g[node][i];
    if (to != pi) {
      fix_down[node] += go(g, inv, to, node, c, dep + 1);
    }
  }
  for (int i = 0; i < (int)inv[node].size(); ++i) {
    int to = inv[node][i];
    if (to != pi) {
      fix_down[node] += go(g, inv, to, node, c + 1, dep + 1) + 1;
    }
  }
  return fix_down[node];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    graph g(n), inv(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      inv[v].push_back(u);
    }
    int best = n;
    go(g, inv, 0, 0, 0, 0);

    for (int i = 0; i < n; ++i)
      best = min(best, fix_down[0] - cur_path[i] + fix_up[i]);

    cout << best << endl;
    int first = 0;
    for (int i = 0; i < n; ++i)
      if ((fix_down[0] - cur_path[i] + fix_up[i]) == best) {
        if (first) cout << ' ';
        first = 1;
        cout << (i + 1);
      }
    cout << endl;
  }
  return 0;
}
