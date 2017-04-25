// http://codeforces.com/contest/505/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define D2(x, y) cout << #x " = " << (x) << " , " << #y " = " << (y) << endl

const int MN = 100001;

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


tarjan_scc scc;

int dfs(vector<vector<int>> &g, vector<int> &vi, vector<int> &c, vector<int> &s,  int node, int &cool) {
  if (vi[node])
    return 0;
  vi[node] = true;
  if (c[node])
    cool = 0;

  int ans = s[node];
  for (int i = 0; i < g[node].size(); ++i) {
    ans += dfs(g, vi, c, s, g[node][i], cool);
  }
  return ans;
}

void solve(int n, int m) {
  vector<vector<int>> g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }

  scc.init();
  for (int i = 0; i < n; ++i) if (scc.scc[i] == -1)
    scc.compute(g, i);

  int k = scc.current_scc;
  vector<int> comp(k), cycle(k);
  vector<vector<int>> r(k);
  for (int i = 0; i < n; ++i) {
    comp[scc.scc[i]]++;
    for (int j = 0; j < g[i].size(); ++j) {
      if (scc.scc[i] != scc.scc[g[i][j]]) {
        r[scc.scc[i]].push_back(scc.scc[g[i][j]]);
        r[scc.scc[g[i][j]]].push_back(scc.scc[i]);
      } else {
        cycle[scc.scc[i]] = true;
      }
    }
  }
  int ans = 0;
  vector<int> vi(k);

  for (int i = 0; i < k; ++i) if (!vi[i]) {
    int cool = true;
    ans += dfs(r, vi, cycle, comp, i, cool);
    if (cool)
      ans--;
  }
  cout << ans << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m)
    solve(n, m);
  return 0;
}