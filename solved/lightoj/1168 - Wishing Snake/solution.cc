
#include <bits/stdc++.h>

using namespace std;

const int MN = 1000 + 10;

struct SCC {
  vector<vector<int> > g, gr;
  vector<bool> used;
  vector<int> order, component;

  SCC(vector<vector<int> > &adj) {
    g = adj;
    int n = g.size();
    gr.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < int(g[i].size()); j++) {
        int to = g[i][j];
        gr[to].push_back(i);
      }
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++)
      if (!used[i])
        gen_time(i);

    used.assign(n, false);
    component.assign(n, -1);
    int component_id = 0;
    for (int i = n - 1; i >= 0; i--) {
      int v = order[i];
      if (!used[v]) {
        vector<int> cur_component;
        dfs(cur_component, v);
        for (int j = 0; j < int(cur_component.size()); j++) {
          component[cur_component[j]] = component_id;
        }
        component_id++;
      }
    }
  }

  void gen_time(int node) {
    used[node] = true;
    for (int i = 0; i < int(g[node].size()); i++)
      if (!used[g[node][i]])
        gen_time(g[node][i]);
    order.push_back(node);
  }

  void dfs(vector<int> &cur, int node) {
    used[node] = true;
    cur.push_back(node);
    for (int i = 0; i < int(gr[node].size()); i++) {
      if (!used[gr[node][i]])
        dfs(cur, gr[node][i]);
    }
  }
};

void solve() {
  int n;
  scanf("%d", &n);
  vector<vector<int> > g(MN);
  set<int> all_nodes;
  while (n--) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      all_nodes.insert(u);
      all_nodes.insert(v);
    }
  }

  SCC scc(g);

  set<int> all_components;
  for (set<int>::iterator it = all_nodes.begin(); it != all_nodes.end(); it++)
    all_components.insert(scc.component[*it]);

  vector<vector<int> > comp(MN);
  for (int i = 0; i < MN; i++) {
    for (int j = 0; j < int(g[i].size()); j++) {
      int to = g[i][j];
      int u = scc.component[i], v = scc.component[to];
      // debug(i, to, u, v);
      if (u != v) {
        comp[u].push_back(v);
      }
    }
  }
  int start = scc.component[0];
  int ok = true;
  set<int> seen;
  seen.insert(start);
  while (comp[start].size() != 0 && ok) {
    if (comp[start].size() != 1)
      ok = false;
    else {
      start = comp[start][0];
      seen.insert(start);
    }
  }

  ok &= seen == all_components;
  puts(ok ? "YES" : "NO");
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}

