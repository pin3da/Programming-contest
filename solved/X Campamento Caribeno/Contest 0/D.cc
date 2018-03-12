#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

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

void add_edge(vector<vector<edge>> &g, int u, int v) {
  int id_u_v = g[u].size();
  int id_v_u = g[v].size();
  g[u].emplace_back(v, id_v_u); // id of the parent in the child's list (g[v][id] -> u)
  g[v].emplace_back(u, id_u_v); // id of the parent in the child's list (g[u][id] -> v)
}


const int MN = 100000 + 100;
state dp[MN];

int sz(vector<vector<edge>> &g, int node, int id_parent) {
  state &s = dp[node];
  if (!s.seen) {
    int ans = 1;
    s.partial.assign(g[node].size(), 0);  // create the list of partial results.
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;
      if (i != id_parent) {
        long long tmp = sz(g, to, pid);
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
      long long tmp = sz(g, g[node][s.missing].to, g[node][s.missing].p_id);
      s.partial[s.missing] = tmp;
      s.total += tmp;
      s.missing = -1;
    }

    long long extra = (id_parent == -1) ? 0 : s.partial[id_parent];
    return s.total - extra;
  }
}


state dp_sum[MN];
long long sum(vector<vector<edge>> &g, int node, int id_parent) {
  state &s = dp_sum[node];
  if (!s.seen) {
    long long ans = 0;
    s.partial.assign(g[node].size(), 0);  // create the list of partial results.
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;
      if (i != id_parent) {
        long long tmp = sum(g, to, pid) + sz(g, to, pid);
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
      int to = g[node][s.missing].to, pid = g[node][s.missing].p_id;
      long long tmp = sum(g, to, pid) + sz(g, to, pid);
      s.partial[s.missing] = tmp;
      s.total += tmp;
      s.missing = -1;
    }

    long long extra = (id_parent == -1) ? 0 : s.partial[id_parent];
    return s.total - extra;
  }

}

void solve() {
  int n; cin >> n;
  vector<vector<edge>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    add_edge(g, u - 1, v - 1);
  }

  for (int i = 0; i < n; i++) {
    dp[i].clear();
    dp_sum[i].clear();
  }

  vector<long long> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = sum(g, i, -1);
  }

  long long best = *min_element(ans.begin(), ans.end());
  vector<int> cool;
  for (int i = 0; i < n; i++) {
    if (ans[i] == best) {
      cool.push_back(i + 1);
    }
  }

  cout << best << " " << cool.size();

  for (int i = 0; i < int(cool.size()); i++) {
    cout << " " << cool[i];
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

