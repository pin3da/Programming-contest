using namespace std;
#include <bits/stdc++.h>

struct edge{
  int to, w;
  edge() {}
  edge(int b, int c) : to(b), w(c) {}
};

int dfs(vector<vector<edge> > &g, int node, int pi) {
  if (node == 0)
    return 0;
  for (int i = 0; i < g[node].size(); ++i) {
    if (g[node][i].to != pi)
      return dfs(g, g[node][i].to, node) + g[node][i].w;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<edge> > g(n);
  int u, v, w;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v >> w;
    u--;v--;
    g[u].push_back(edge(v, 0));
    g[v].push_back(edge(u, w));
  }
  printf("%d\n", min(dfs(g, g[0][0].to, 0) + g[0][0].w , dfs(g, g[0][1].to, 0) + g[0][1].w));
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

}
