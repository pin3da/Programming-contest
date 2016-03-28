#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  int to, w;
  edge() {}
  edge(int a, int b) : to(a), w(b) {}
};


const int MN  = 100000 + 10; // Max number of elements
const int ML  = 18; // ceil(log2(MN));
const int inf = 1000001;

struct lowest_ca {
  int T[MN], L[MN], W[MN];
  int P[MN][ML], MI[MN][ML], MA[MN][ML];

  void dfs(vector<vector<edge> > &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = W[root] = 0;
      T[root] = -1;
    }
    for (int i = 0; i < g[root].size(); ++i) {
      int to = g[root][i].to;
      if (to != pi) {
        T[to] = root;
        W[to] = g[root][i].w;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(vector<vector<edge> > &g, int root) {
    dfs(g, root);
    int N = g.size(), i, j;

    for (i = 0; i < N; i++) {
      for (j = 0; 1 << j < N; j++) {
        P[i][j] = -1;
        MA[i][j] = -inf;
        MI[i][j] = inf;
      }
    }

    for (i = 0; i < N; i++) {
      P[i][0] = T[i];
      MI[i][0] = MA[i][0] = W[i];
    }

    for (j = 1; 1 << j < N; j++)
      for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1) {
          P[i][j] = P[P[i][j - 1]][j - 1];
          MI[i][j] = min(MI[i][j-1], MI[ P[i][j - 1] ][j - 1]);
          MA[i][j] = max(MA[i][j-1], MA[ P[i][j - 1] ][j - 1]);
        }
  }

  pair<int, int> query(int p, int q) {
    int tmp, log, i;

    int mmin = inf, mmax = -inf;
    if (L[p] < L[q])
      tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
      if (L[p] - (1 << i) >= L[q]) {
        mmin = min(mmin, MI[p][i]);
        mmax = max(mmax, MA[p][i]);
        p = P[p][i];
      }

    if (p == q)
      // return p;
      return make_pair(mmin, mmax);

    for (i = log; i >= 0; i--)
      if (P[p][i] != -1 && P[p][i] != P[q][i]) {
        mmin = min(mmin, min(MI[p][i], MI[q][i]));
        mmax = max(mmax, max(MA[p][i], MA[q][i]));
        p = P[p][i], q = P[q][i];
      }

    // return T[p];
    return make_pair(min(mmin, min(MI[p][0], MI[q][0])), max(mmax, max(MA[p][0], MA[q][0])));
  }
};


lowest_ca lca;

struct st {
  int u, v, w;
  st(int a, int b, int c) : u(a), v(b), w(c) {}
  bool operator < (const st &o) const {
    return w > o.w;
  }
};

int pi[MN];

int fs(int x) {
  return (pi[x] == x) ? x : pi[x] = fs(pi[x]);
}

int js(int x, int y) {
  pi[fs(x)] = fs(y);
}

vector<vector<edge>> mst(vector<st> &e, int n)  {
  sort(e.begin(), e.end());
  vector<vector<edge>> g(n);
  for (int i = 0; i < n + 10; ++i) pi[i] = i;
  for (int i = 0; i < e.size(); ++i) {
    if (fs(e[i].v) != fs(e[i].u)) {
      js(e[i].v, e[i].u);
      g[e[i].v].emplace_back(e[i].u, e[i].w);
      g[e[i].u].emplace_back(e[i].v, e[i].w);
    }
  }
  return g;
}

void solve(int n) {
  int m, q;
  cin >> m >> q;
  int u, v, w;
  vector<st> e;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u--; v--;
    e.emplace_back(u, v, w);
  }

  vector<vector<edge>> g = mst(e, n);
  lca.init(g, 0);

  while (q--) {
    cin >> u >> v;
    u--;v--;
    pair<int, int> ans = lca.query(u, v);
    // printf("%d %d\n", ans.first, ans.second);
    cout << ans.first << endl;
  }
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
