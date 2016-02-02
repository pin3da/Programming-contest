#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge{
  int u, v, w;
};

typedef  vector<vector<edge>> graph;

bool dfs(graph &g, vector<int> &t, int node) {
  for (auto e : g[node])
    if (dfs(g, t, e.v))
      t[node] |= true;

  return t[node];
}

int go(graph &g, vector<int> &t, int node, bool acc) {
  if (!t[node]) return 0;

  int total = 0;
  for (auto e : g[node]) {
    if (t[e.v]) {
      if (acc)
        total += go(g, t, e.v, acc) + e.w;
      else
        total = max(total, go(g, t, e.v, acc) + e.w);
    }
  }
  return total;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, f;
  while (cin >> n >> f) {
    vector<vector<edge>> g(n);
    vector<int>  target(n);
    edge e;
    for (int i = 0; i < n - 1; ++i) {
      cin >> e.u >> e.v >> e.w;
      e.u--; e.v--;
      g[e.u].push_back(e);
    }
    int x;
    for (int i = 0; i < f; ++i) {
      cin >> x;
      target[x - 1] =  true;
    }
    dfs(g, target, 0);

    cout <<  go(g, target, 0, true) - go(g, target, 0, false) << endl;
  }
  return 0;
}

