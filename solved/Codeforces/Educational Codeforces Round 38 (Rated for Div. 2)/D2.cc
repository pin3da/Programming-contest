#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

struct edge {
  int to, p_id;
  long long w;
  edge (int a, int b, long long c) : to(a), p_id(b), w(c) {}
};

struct state {
  bool seen;
  long long missing;
  multiset<long long> total;
  vector<long long> partial;

  state() { clear(); }

  void clear() {
    seen = false;
    missing = 0;
    total.clear();
    partial.clear();
  }
};

typedef vector<vector<edge>> graph;

void add_edge(graph &g, int u, int v, long long w) {
  int id_u_v = g[u].size();
  int id_v_u = g[v].size();
  g[u].emplace_back(v, id_v_u, w); // id of the parent in the child's list (g[v][id] -> u)
  g[v].emplace_back(u, id_u_v, w); // id of the parent in the child's list (g[u][id] -> v)
}


const int MN = 200000 + 1000;
state dp[MN];
long long W[MN];
const long long INF = numeric_limits<long long>::max();


int go(graph &g, int node, int id_parent) {

  state &s = dp[node];

  if (!s.seen) {
    long long ans = W[node];
    s.total.insert(ans);
    s.partial.assign(g[node].size(), INF);  // create the list of partial results.
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;
      if (i != id_parent) {
        long long tmp = go(g, to, pid) + 2LL * g[node][i].w;
        ans = min(ans, tmp);
        s.total.insert(tmp);
        s.partial[i] = tmp;
      }
    }

    s.missing = id_parent;
    s.seen = true;

    return ans;
  } else {

    if (s.missing == id_parent) { // the same id_parent than before, so we can not complete the results yet
      return *(s.total.begin());
    }

    if (s.missing != -1) { // only one missing and is different of 'id_parent'
      long long tmp = go(g, g[node][s.missing].to, g[node][s.missing].p_id) + 2LL * g[node][s.missing].w;
      s.partial[s.missing] = tmp;
      s.total.insert(tmp);
      s.missing = -1;
    }

    long long extra = (id_parent == -1) ? INF : s.partial[id_parent];
    auto best = s.total.begin();
    if ((*best) == extra) best++;
    if (best == s.total.end()) return W[node];
    return *best;
  }
}


void solve() {
  int n, m; cin >> n >> m;
  graph g(n);

  for (int i = 0; i < m; i++) {
    int u, v; long long w;
    read(u, v, w);

    add_edge(g, u - 1, v - 1, w);
  }

  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }

  debug("pasa");

  for (int i = 0; i < n; i++) {
    debug(go(g, i, -1));
    cout << go(g, i, -1) << " ";
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

