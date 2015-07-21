using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 20002;

struct Reader {
  int b; Reader() { read(); }
  void read() { b = getchar_unlocked(); }
  void skip() { while (0 <= b && b <= 32) read(); }
  unsigned int next_u32() {
    unsigned int v=0; for (skip(); 48<=b&&b<=57; read()) v = 10*v+b-48; return v; }
};

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

Reader rd;
void solve() {
  int n = rd.next_u32(), m = rd.next_u32();
  vector<vector<int> > g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    u = rd.next_u32(); v = rd.next_u32();
    u--;v--;
    g[u].push_back(v);
  }

  tar_scc.init();
  for (int i = 0; i < n; ++i) {
    if (tar_scc.scc[i] == -1)
      tar_scc.compute(g, i);
  }

  if (tar_scc.current_scc <= 1) {
    puts("0");
    return;
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
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = rd.next_u32();
  for (int i = 0; i < tc; ++i) {
    // printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}

