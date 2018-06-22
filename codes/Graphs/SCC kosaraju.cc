struct SCC {
  vector<vector<int> > g, gr;
  vector<bool> used;
  vector<int> order, component;
  int total_components;

  SCC(vector<vector<int> > &adj) {
    g = adj;
    int n = g.size();
    gr.resize(n);
    for (int i = 0; i < n; i++)
      for (auto to : g[i])
        gr[to].push_back(i);

    used.assign(n, false);
    for (int i = 0; i < n; i++)
      if (!used[i])
        GenTime(i);

    used.assign(n, false);
    component.assign(n, -1);
    total_components = 0;
    for (int i = n - 1; i >= 0; i--) {
      int v = order[i];
      if (!used[v]) {
        vector<int> cur_component;
        Dfs(cur_component, v);
        for (auto node : cur_component)
          component[node] = total_components;
        total_components++;
      }
    }
  }

  void GenTime(int node) {
    used[node] = true;
    for (auto to : g[node])
      if (!used[to])
        GenTime(to);
    order.push_back(node);
  }

  void Dfs(vector<int> &cur, int node) {
    used[node] = true;
    cur.push_back(node);
    for (auto to : gr[node])
      if (!used[to])
        Dfs(cur, to);
  }

  vector<vector<int>> CondensedGraph() {
    vector<vector<int>> ans(total_components);
    for (int i = 0; i < int(g.size()); i++) {
      for (int to : g[i]) {
        int u = component[i], v = component[to];
        if (u != v)
          ans[u].push_back(v);
      }
    }
    return ans;
  }
};

