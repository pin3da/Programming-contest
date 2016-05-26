// Wrong Answer ):
#include <bits/stdc++.h>

using namespace std;

const int MN = 101010;
int p[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  if (fs(x) == fs(y)) return false;
  p[fs(x)] = fs(y);
  return true;
}

struct edge{
  int to, id;
  edge(int a, int b) : to(a), id(b) {}
};

struct graph {
  vector<vector<edge> > g;
  vector<int> vi, low, d, pi, is_b;

  int ticks, edges;

  graph(int n, int m) {
    g.assign(n, vector<edge>());
    is_b.assign(m, 0);
    vi.resize(n);
    low.resize(n);
    d.resize(n);
    pi.resize(n);
    edges = 0;
  }

  void add_edge(int u, int v, int id) {
    g[u].push_back(edge(v, id));
    g[v].push_back(edge(u, id));
    edges++;
  }

  void dfs(int u) {
    vi[u] = true;
    d[u] = low[u] = ticks++;
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].to;
      if (v == pi[u]) continue;
      if (!vi[v]) {
        pi[v] = u;
        dfs(v);
        if (d[u] < low[v])
          is_b[g[u][i].id] = true;

        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], d[v]);
      }
    }
  }

  void comp_bridges() {
    fill(pi.begin(), pi.end(), -1);
    fill(vi.begin(), vi.end(), 0);
    fill(low.begin(), low.end(), 0);
    fill(d.begin(), d.end(), 0);
    ticks = 0;
    for (int i = 0; i < g.size(); ++i)
      if (!vi[i]) dfs(i);
  }
};

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> belongs(n);
    vector<vector<int>> c(m);
    vector<int> degree(m);
    graph g(m, n);
    for (int i = 0; i < m; ++i) {
      int k, t;
      cin >> k;
      while (k--) {
        cin >> t;
        belongs[t].emplace_back(i);
        c[i].emplace_back(t);
      }
    }
    for (int i = 0; i < m; ++i) p[i] = i;
    for (int i = 0; i < n; ++i) {
      vector<int> &t = belongs[i];
      assert(t.size() > 0);
      assert(t.size() <= 2);
      if (t.size() == 1) {
        degree[t[0]] += 2;
        g.add_edge(t[0], t[0], i);
      }
      for (int j = 0; j < t.size(); ++j) {
        for (int k = j + 1; k < t.size(); ++k) {
          degree[t[k]]++;
          degree[t[j]]++;
          g.add_edge(t[k], t[j], i);
          js(t[k], t[j]);
        }
      }
    }
    set<int> components;
    for (int i = 0; i < m; ++i)
      if (degree[i] > 0)
        components.insert(fs(i));

    if (components.size() > 1) {
      cout << -1 << endl;
      continue;
    }

    vector<int> odd;
    for (int i = 0; i < m; ++i) {
      if (degree[i] & 1)
        odd.emplace_back(i);
    }

    if ((odd.size() != 0) && (odd.size() != 2)) {
      cout << -1 << endl;
      continue;
    }

    int best = MN;
    if (odd.size()) {
      g.comp_bridges();
      for (auto &i : odd) {
        int cur_best = MN;
        for (auto &to : g.g[i]) {
          if (g.is_b[to.id]) continue;
          else cur_best = min(cur_best, to.id);
        }
        if (cur_best == MN)
          for (auto &to : g.g[i])
            cur_best = min(cur_best, to.id);
        best = min(best, cur_best);
      }
    } else {
      best = 0;
    }
    cout << best << endl;
  }
  return 0;
}
