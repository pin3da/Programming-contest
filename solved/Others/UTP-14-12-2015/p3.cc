/**
 * WA
 * */
using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int inf = 1000000000;
struct edge{
  int v, w; edge(){} edge(int v, int w) : v(v), w(w) {}
};

void dfs(vector<vector<edge> > &g, vector<int> &vi, int node) {
  if (vi[node]) return;
  vi[node] = true;
  for (int i = 0; i < g[node].size(); ++i)
    dfs(g, vi, g[node][i].v);
}

vector<int> bellman(vector<vector<edge> > &g, int s) {
  int n = g.size();
  vector<int> d(n, inf), p(n, -1), vi(n);
  vector<int> in_cycle;
  d[s] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      for (int k = 0; k < g[u].size(); ++k) {
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          p[v] = u;
        }
      }
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      for (int k = 0; k < g[u].size(); ++k) {
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]) {
          dfs(g, vi, v);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (vi[i])
      in_cycle.push_back(i);
  }
  return in_cycle;
}

bool rechable(vector<vector<int> > &g, vector<int> &c, vector<int> &vi,
              set<int> &target, int node, int energy) {

  energy -= c[node];
  if (energy <= 0) return false;
  if (target.count(node)) return true;
  vi[node] = true;
  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i];
    if (!vi[to])
      if (rechable(g, c, vi, target, to, energy))
        return true;
  }
  return false;
}

void solve(int n) {
  vector<vector<int> > g(n);
  vector<vector<edge> > g2(n);
  vector<int> cost(n), vi(n);
  int t, v;
  for (int i = 0; i < n; ++i) {
    cin >> cost[i] >> t;
    cost[i] *= -1;
    for (int j = 0; j < t; ++j) {
      cin >> v; v--;
      g[i].push_back(v);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      v = g[i][j];
      g2[i].push_back(edge(v, cost[v]));
    }
  }

  set<int> target;
  target.insert(g.size() - 1);
  if (rechable(g, cost, vi, target, 0, 100))
    cout << "winnable" << endl;
  else {
    vector<int> c = bellman(g2, 0);
    for (int i = 0; i < c.size(); ++i) {
      target.insert(c[i]);
    }

    vi.assign(n, 0);
    if (rechable(g, cost, vi, target, 0, 100))
      cout << "winnable" << endl;
    else
      cout << "hopeless" << endl;
  }
}

int main() {
  int n;
  while (cin >> n && n > 0)
    solve(n);
  return 0;
}
