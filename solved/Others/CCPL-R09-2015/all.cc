using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 20002;

struct tarjan_scc {
  int scc[MN], low[MN], d[MN], stacked[MN];
  int ticks, current_scc;
  deque<int> s;
  tarjan_scc() {}
  void init () {
    memset(scc, -1, sizeof scc);
    memset(d, -1, sizeof d);
    memset(stacked, 0, sizeof stacked);
    s.clear();
    ticks = current_scc = 0;
  }
  void compute(vector<vector<int> > &g, int u) {
    d[u] = low[u] = ticks++;
    s.push_back(u);
    stacked[u] = true;
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i];
      if (d[v] == -1)
        compute(g, v);
      if (stacked[v]) {
        low[u] = min(low[u], low[v]);
      }
    }

    if (d[u] == low[u]) {
      int v;
      do {
        v = s.back();s.pop_back();
        stacked[v] = false;
        scc[v] = current_scc;
      } while (u != v);
      current_scc++;
    }
  }
};

tarjan_scc t;

void solve() {
  int n, m;
  t.init();
  cin >> n >> m;
  vector<vector<int> > g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }

  for (int i = 0; i < n; ++i)
    if (t.scc[i] == -1)
      t.compute(g, i);

  vector<int> in(t.current_scc, 0);
  for (int i = 0; i < n; ++i) {
    // cout << t.scc[i] << " ";
    for (int j = 0; j < g[i].size(); ++j) {
      u = i; v = g[i][j];
      if (t.scc[u] != t.scc[v]) {
        in[t.scc[v]]++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < in.size(); ++i) {
    if (in[i] == 0)
      ans++;
  }

  printf("%d\n", ans);
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
