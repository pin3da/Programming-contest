#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 100000 + 100;
const int ML = 19;

struct lowest_ca {
  int T[MN], L[MN];
  int P[MN][ML];

  void dfs(vector<vector<int>> &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = 0;
      T[root] = -1;
    }
    for (int i = 0; i < (int)g[root].size(); ++i) {
      int to = g[root][i];
      if (to != pi) {
        T[to] = root;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(vector<vector<int>> &g, int root) {
    // g is undirected
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

  int dist(int p, int q) {
    int l = lca(p, q);
    return L[p] + L[q] - 2 * L[l];
  }
};

lowest_ca tree;


int test(int a, int b, int c) {
  if (tree.lca(b, a) == b) {
    if (tree.lca(b, c) == b) {
      return tree.dist(tree.lca(c, a), c);
    }
    return tree.dist(tree.lca(a, b), c);
  } else if (tree.lca(b, a) == a) {
    if (tree.lca(a, c) == a)
      return tree.dist(tree.lca(c, b), c);
    return tree.dist(a, c);
  }
  vector<int> op = {
    tree.dist(c, tree.lca(c, b)),
    tree.dist(c, tree.lca(c, a)),
  };
  if (tree.L[tree.lca(c, b)] > tree.L[tree.lca(a, c)]) {
    return max(*min_element(op.begin(), op.end()), tree.dist(tree.lca(c, b), a));
  }
  if (tree.L[tree.lca(c, a)] > tree.L[tree.lca(b, c)]) {
    return max(*min_element(op.begin(), op.end()), tree.dist(tree.lca(c, a), b));
  }
  return *min_element(op.begin(), op.end());
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int pi; cin >> pi;
    pi--;
    g[i].push_back(pi);
    g[pi].push_back(i);
  }

  tree.init(g, 0);

  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;c--;

    int ans = 0;
    ans = max(ans, test(a, b, c));
    ans = max(ans, test(c, b, a));
    ans = max(ans, test(a, c, b));
    cout << ans + 1 << endl;
  }

  return 0;
}
