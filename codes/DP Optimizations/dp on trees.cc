/**
 * This trick is very useful when doing DP on trees, basically, you can save
 * the answer for each node as if it was the root of the tree. Partial results
 * are also stored in order to query subtrees (taking the root and exclude some
 * child).
 *
 * problems:
 *   - http://codeforces.com/gym/101161, problem I : Sky tax
 *   - http://codeforces.com/contest/791/problem/D
 * */


struct edge {
  int to, p_id;
  edge (int a, int b) : to(a), p_id(b) {}
};

struct state {
  bool seen;
  long long missing;
  long long total;
  vector<long long> partial;

  state() { clear(); }

  void clear() {
    seen = false;
    missing = 0;
    total = 0;
    partial.clear();
  }
};

void add_edge(int u, int v) {
  int id_u_v = g[u].size();
  int id_v_u = g[v].size();
  g[u].emplace_back(v, id_v_u); // id of the parent in the child's list (g[v][id] -> u)
  g[v].emplace_back(u, id_u_v); // id of the parent in the child's list (g[u][id] -> v)
}


int go(int node, int id_parent) {

  state &s = dp[node];

  if (!s.seen) {
    int ans = 1;
    s.partial.assign(g[node].size(), 0);  // create the list of partial results.
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;
      if (i != id_parent) {
        int tmp = go(to, pid);
        ans += tmp;
        s.partial[i] = tmp;
      }
    }

    s.missing = id_parent;
    s.total = ans;
    s.seen = true;

    return ans;
  } else {

    if (s.missing == id_parent) { // the same id_parent than before, so we can not complete the results yet
      return s.total;
    }

    if (s.missing != -1) { // only one missing and is different of 'id_parent'
      int tmp = go(g[node][s.missing].to, g[node][s.missing].p_id);
      s.partial[s.missing] = tmp;
      s.total += tmp;
      s.missing = -1;
    }

    int extra = (id_parent == -1) ? 0 : s.partial[id_parent];
    return s.total - extra;
  }
}
