#include <bits/stdc++.h>

using namespace std;

const int MN = 10000 + 10;
const int ML = 16;

struct LCA {
  int T[MN], L[MN];
  int P[MN][ML];

  void dfs(vector<vector<int>> &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = 0;
      T[root] = -1;
    }
    for (int to : g[root]) {
      if (to != pi) {
        T[to] = root;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(vector<vector<int>> &g, int root) {
    dfs(g, root);
    int N = g.size(), i, j;

    for (i = 0; i < N; i++) {
      for (j = 0; 1 << j < N; j++) {
        P[i][j] = -1;
      }
    }

    for (i = 0; i < N; i++) {
      P[i][0] = T[i];
    }

    for (j = 1; 1 << j < N; j++)
      for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1) {
          P[i][j] = P[P[i][j - 1]][j - 1];
        }
  }

  int lca(int p, int q) {
    int tmp, log, i;

    if (L[p] < L[q])
      tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
      if (L[p] - (1 << i) >= L[q]) {
        p = P[p][i];
      }

    if (p == q)
      return p;

    for (i = log; i >= 0; i--)
      if (P[p][i] != -1 && P[p][i] != P[q][i]) {
        p = P[p][i], q = P[q][i];
      }

    return T[p];
  }
};

LCA lca;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int m; cin >> m;
    while (m--) {
      int tmp; cin >> tmp;
      tmp--;
      g[i].emplace_back(tmp);
      g[tmp].emplace_back(i);
    }
  }
  int q;
  cin >> q;
  lca.init(g, 0);

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    cout << lca.lca(u, v) + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case " << (i + 1) << ":" << "\n";
    solve();
  }
  return 0;
}
