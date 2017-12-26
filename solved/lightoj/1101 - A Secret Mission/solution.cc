#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;


const int MN = 50000 + 100;
const int ML = 16;

struct edge {
  int u, v;
  long long w;
  edge() {}
  edge(int a, int b, long long c) : u(a), v(b), w(c) {}
  bool operator<(const edge &o) const {
    return w < o.w;
  }
};

struct lowest_ca {
  int T[MN], L[MN], W[MN];
  int P[MN][ML], MA[MN][ML];

  void dfs(vector<vector<edge> > &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = W[root] = 0;
      T[root] = -1;
    }
    for (int i = 0; i < (int)g[root].size(); ++i) {
      int to = g[root][i].v;
      if (to != pi) {
        T[to] = root;
        W[to] = g[root][i].w;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(vector<vector<edge> > &g, int root) {
    // g is undirected
    dfs(g, root);
    int N = g.size(), i, j;

    for (i = 0; i < N; i++) {
      for (j = 0; 1 << j < N; j++) {
        P[i][j] = -1;
        MA[i][j] = 0;
      }
    }

    for (i = 0; i < N; i++) {
      P[i][0] = T[i];
      MA[i][0] = W[i];
    }

    for (j = 1; 1 << j < N; j++)
      for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1) {
          P[i][j] = P[P[i][j - 1]][j - 1];
          MA[i][j] = max(MA[i][j-1], MA[ P[i][j - 1] ][j - 1]);
        }
  }

  int query(int p, int q) {
    int tmp, log, i;

    int best = 0;
    if (L[p] < L[q])
      tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
      if (L[p] - (1 << i) >= L[q]) {
        best = max(best, MA[p][i]);
        p = P[p][i];
      }

    if (p == q)
      // return p;
      return best;

    for (i = log; i >= 0; i--)
      if (P[p][i] != -1 && P[p][i] != P[q][i]) {
        best = max(best, max(MA[p][i], MA[q][i]));
        p = P[p][i], q = P[q][i];
      }

    // return T[p];
    return max(best, max(MA[p][0], MA[q][0]));
  }
};

struct dsu {
  int p[MN];

  void init(int n) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  }

  int join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py)
      return 0;
    p[px] = py;
    return 1;
  }
};

dsu ds;

vector<edge> mst(vector<edge> &g, int n) {
  ds.init(n);
  sort(g.begin(), g.end());
  vector<edge> ans;

  for (size_t i = 0; i < g.size(); i++) {
    edge &e = g[i];
    if (ds.join(e.u, e.v)) {
      ans.push_back(e);
    }
  }
  return ans;
}


lowest_ca lca;

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<edge> edges(m);
  for (int i = 0; i < m; i++) {
    edge &e = edges[i];
    scanf("%d%d%lld", &e.u, &e.v, &e.w);
    e.u--;
    e.v--;
  }

  vector<edge> tree = mst(edges, n);
  vector<vector<edge> > g(n);
  for (size_t i = 0; i < tree.size(); i++) {
    edge &e = tree[i];
    g[e.u].push_back(e);
    g[e.v].push_back(edge(e.v, e.u, e.w));
  }

  lca.init(g, 0);

  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca.query(u - 1, v - 1));
  }

}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
