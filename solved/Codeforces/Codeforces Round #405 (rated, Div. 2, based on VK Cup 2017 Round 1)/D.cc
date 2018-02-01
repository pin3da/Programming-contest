#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

const int MN = 200001;
const int MK = 6;

int K;

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

state dp1[MN];
state dp2[MK][MN];

vector<edge> g[MN];

void add_edge(int u, int v) {
  int id_u_v = g[u].size();
  int id_v_u = g[v].size();
  g[u].emplace_back(v, id_v_u); // id del padre en el hijo
  g[v].emplace_back(u, id_u_v); // id del padre en el hijo
}


int go_size(int node, int id_parent) {

  state &s = dp1[node];

  if (!s.seen) {
    int ans = 1;
    s.partial.assign(g[node].size(), 0);
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;
      if (i != id_parent) {
        int tmp = go_size(to, pid);
        ans += tmp;
        s.partial[i] = tmp;
      }
    }

    s.missing = id_parent;
    s.total = ans;
    s.seen = true;

    return ans;
  } else {

    if (s.missing == id_parent) { // the same id_parent than before
      return s.total;
    }

    if (s.missing != -1) { // one missing and is different of id_parent :D
      int tmp = go_size(g[node][s.missing].to, g[node][s.missing].p_id);
      s.partial[s.missing] = tmp;
      s.total += tmp;
      s.missing = -1;
    }

    int extra = (id_parent == -1) ? 0 : s.partial[id_parent];
    return s.total - extra;
  }
}

long long go(int node, int id_parent, int x) {
  state &s = dp2[x][node];

  if (!s.seen) {
    long long ans = 0;
    s.partial.assign(g[node].size(), 0);
    for (int i = 0; i < int(g[node].size()); i++) {
      int to = g[node][i].to;
      int pid = g[node][i].p_id;

      if (i != id_parent) {

        long long tmp = 0;
        if (x) tmp = go(to, pid, x - 1);
        else   tmp = go(to, pid, K - 1) + go_size(to, pid);

        ans += tmp;
        s.partial[i] = tmp;
      }
    }

    s.missing = id_parent;
    s.total = ans;
    s.seen = true;

    return ans;
  } else {

    if (s.missing == id_parent) { // the same id_parent than before
      return s.total;
    }

    if (s.missing != -1) { // one missing and is different of id_parent :D
      long long tmp = 0;
      int to = g[node][s.missing].to, pid = g[node][s.missing].p_id;
      if (x) tmp = go(to, pid, x - 1);
      else   tmp = go(to, pid, K - 1) + go_size(to, pid);

      s.partial[s.missing] = tmp;
      s.total += tmp;
      s.missing = -1;
    }

    long long extra = (id_parent == -1) ? 0 : s.partial[id_parent];
    return s.total - extra;
  }

}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n >> K;
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    u--;v--;
    add_edge(u, v);
  }

  for (int i = 0; i < n; i++) {
    dp1[i].clear();
    for (int j = 0; j < MK; j++)
      dp2[j][i].clear();
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans += go(i, -1, 0);
  cout << (ans >> 1) << endl;
  return 0;
}
