using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 20002;

struct tarjan_scc {
  int scc[MN], low[MN], d[MN], stacked[MN];
  int ticks, current_scc;
  deque<int> s; // used as stack.

  tarjan_scc() {}

  void init () {
    memset(scc, -1, sizeof scc);
    memset(d, -1, sizeof d);
    memset(stacked, 0, sizeof stacked);
    s.clear();
    ticks = current_scc = 0;
  }
  void tarjan(vector<vector<int> > &g, int u){
    d[u] = low[u] = ticks++;
    s.push_back(u);
    stacked[u] = true;
    const vector<int> &out = g[u];
    for (int k=0, m=out.size(); k<m; ++k){
      const int &v = out[k];
      if (d[v] == -1){
        tarjan(g, v);
        low[u] = min(low[u], low[v]);
      }else if (stacked[v]){
        low[u] = min(low[u], low[v]);
      }
    }
    if (d[u] == low[u]){
      int v;
      do{
        v = s.back();
        s.pop_back();
        stacked[v] = false;
        scc[v] = current_scc;
      }while (u != v);
      current_scc++;
    }
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

    if (d[u] == low[u]) { // root
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

tarjan_scc tar_scc;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }

  tar_scc.init();
  for (int i = 0; i < n; ++i) {
    if (tar_scc.scc[i] == -1)
      tar_scc.tarjan(g, i);
  }

  int a = 0, b = 0;
  vector<int> in(n, 0), out(n, 0);
  for (int u = 0; u < n; ++u) {
    for (int j = 0; j < g[u].size(); ++j) {
      if (tar_scc.scc[g[u][j]] != tar_scc.scc[u]) {
        in[tar_scc.scc[g[u][j]]]++;
        out[tar_scc.scc[u]]++;
      }
    }
  }

  for (int i = 0; i < tar_scc.current_scc; ++i) {
    if (in[i] == 0) a++;
    if (out[i] == 0) b++;
  }
  printf("%d\n", max(b, a));
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
}
