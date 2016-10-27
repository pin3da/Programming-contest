#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct edge {
  int from, to, cost;
  edge(int a, int b, int c) : from(a), to(b), cost(c) {}
};

const int MN = 112345;
long long d[MN];
long long r[MN];

typedef vector<vector<edge> > graph;

long long dfs(graph &g, int node, int pi, long long cur) {
  long long ans = 0;
  r[node] = cur;
  for (int i = 0; i < (int)g[node].size(); ++i) {
    int to = g[node][i].to;
    if (to == pi) continue;
    ans += g[node][i].cost * 2;
    ans += dfs(g, to, node, cur + g[node][i].cost);
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;cin >> n;
  for (int i = 0; i < n + 1; ++i)
    cin >> d[i];

  graph g(n + 1);
  for (int i = 0; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(edge(u, v, w));
    g[v].push_back(edge(v, u, w));
  }

  memset(r, 0, sizeof r);
  long long total = dfs(g, 0, 0, 0);

  // debug(total);
  long long best = total + d[0];
  for (int i = 1; i <= n; ++i) {
    // debug(r[i]);
    best = min(best, total - r[i] + d[i]);
  }
  cout << best << endl;
  return 0;
}
