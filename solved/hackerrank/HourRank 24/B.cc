#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

long long sum = 0;

const int MN = 112345;
int sz[MN];

long long dfs(graph &g, int node, int pi, int dep) {
  long long ans = 0;
  sz[node] = 1;
  for (auto to : g[node]) {
    if (to == pi) continue;
    ans += dfs(g, to, node, dep + 1);
    sz[node] += sz[to];
    ans += (g.size() - sz[to]) * dep;
    sum += dep;
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  sum = 0;
  long long ans = dfs(g, 0, 0, 1);
  cout << fixed << setprecision(10) << double(ans) / double(sum) << endl;
  return 0;
}
