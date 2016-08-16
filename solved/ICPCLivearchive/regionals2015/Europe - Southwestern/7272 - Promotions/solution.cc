#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef vector<vector<int> > graph;

int go(graph &g, vector<int> &dp, int node) {
  if (dp[node] != -1) return dp[node];
  dp[node] = 0;
  for (int i = 0; i < g[node].size(); ++i) {
     dp[node] += go(g, dp, g[node][i]) + 1;
  }
  return dp[node];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int a, b, n, m;
  while (cin >> a >> b >> n >> m) {
    graph g(n), gi(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      gi[v].push_back(u);
    }
    vector<int> subtree(n, -1);
    vector<int> pred(n, -1);
    for (int i = 0; i < n; ++i) {
      go(g, subtree, i);
      go(gi, pred, i);
    }

    int A = 0, B = 0, C = 0;
    for (int i = 0; i < n; ++i) {
      A += (a >= (n - subtree[i]));
      B += (b >= (n - subtree[i]));
      C += pred[i] >= b;
    }
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
  }
  return 0;
}
