using namespace std;
#include <bits/stdc++.h>

struct edge{
  int to, w;
  edge() {}
  edge(int a, int b) : to(a), w(b) {}
};

pair<int, long long> dfs(vector<vector<edge> > &g, vector<bool> &vi, int node, int dist) {
  vi[node] = true;
  int to   = node;
  int best = dist;
  for (int i = 0; i < g[node].size(); ++i ) {
    if (!vi[g[node][i].to]) {
      pair<int, long long> cur = dfs(g, vi, g[node][i].to, dist + g[node][i].w);
      if (cur.second > best) {
        to = cur.first;
        best = cur.second;
      }
    }
  }
  return make_pair(to, best);
}

void solve() {
  int n;
  cin >> n;
  vector<vector<edge> > g(n);
  int u, v, w;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v >> w;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }
  vector<bool> visited(n, 0);
  pair<int, long long> f = dfs(g, visited, 0, 0);
  visited.assign(n, 0);
  printf("%lld\n", dfs(g, visited, f.first, 0).second);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
