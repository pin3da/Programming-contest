#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

int n, x, y;
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

const int MN = 300000 + 100;
vector<edge> g[MN];

void add_edge(int u, int v) {
  int id_u_v = g[u].size();
  int id_v_u = g[v].size();
  g[u].emplace_back(v, id_v_u); // id of the parent in the child's list (g[v][id] -> u)
  g[v].emplace_back(u, id_u_v); // id of the parent in the child's list (g[u][id] -> v)
}

state dp[MN][2];

int go(int node, int id_parent, int seen_x) {

  state &s = dp[node][seen_x];

  if (!s.seen) {
    int ans = 1;
    s.partial.assign(g[node].size(), 0);  // create the list of partial results.
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;
      if (i != id_parent) {
        if (seen_x && to == y) {
          s.partial[i] = 0;
        } else {
          int tmp = go(to, pid, seen_x || (to == x));
          ans += tmp;
          s.partial[i] = tmp;
        }
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
      int to = g[node][s.missing].to;
      if (seen_x && (to == y)) {
        s.partial[s.missing] = 0;
      } else {
        int tmp = go(to, g[node][s.missing].p_id, seen_x); // TODO: fix
        s.partial[s.missing] = tmp;
        s.total += tmp;
      }
      s.missing = -1;
    }

    int extra = (id_parent == -1) ? 0 : s.partial[id_parent];
    return s.total - extra;
  }
}

void solve() {
  cin >> n >> x >> y;
  x--; y--;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    add_edge(u, v);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += go(i, -1, i == x) - 1;
  }
  cout << ans << endl;
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

