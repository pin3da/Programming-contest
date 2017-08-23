#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 5 * 100000 + 100;
const int SN = 708;

struct bit {
  int n;
  int t[2 * MN];

  bit() {
    n = MN;
  }

  void clear() {
    memset(t, 0, sizeof t);
  }

  void add(int where, long long what){
    for (where++; where <= n; where += where & -where){
      t[where] += what;
    }
  }

  long long query(int where){
    long long sum = t[0];
    for (where++; where > 0; where -= where & -where){
      sum += t[where];
    }
    return sum;
  }

  int get(int k) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (query(mid) < k) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};

// Begin MOs algorithm
struct query {
  int a, b, id; //[a, b]
  int u, v, lca;
  query() {}
  query(int x, int y, int i) : a(x), b(y), id(i) {}

  bool operator < (const query &o) const {
    return b < o.b;
  }
};


vector<query> s[SN];
int ans[MN];
struct DS {
  int used[MN];
  int total;
  bit tree;
  void clear() {
    memset(used, 0, sizeof used);
    total = 0;
    tree.clear();
  }
  void update(vector<int> &cost, int id) {
    if (id == 0) return; // root
    if (used[id]) { // erase
      tree.add(cost[id], -1);
      total--;
    } else { // add
      tree.add(cost[id], 1);
      total++;
    }
    used[id] ^= 1;
  }
  long long query() {
    int id = (total >> 1) + 1;
    int id2 = ((total - 1) >> 1) + 1;
    return tree.get(id) + tree.get(id2);
  }
};

DS data;

void solve_mo(vector<query> &queries, vector<int> &a, vector<int> &le,
    vector<int> &cost) {
  for (int i = 0; i < SN; ++i)
    s[i].clear();

  for (int i = 0; i < (int)queries.size(); ++i) {
    int b = queries[i].a;
    s[b / SN].push_back(queries[i]);
  }


  for (int i = 0; i < SN; ++i) {
    if (s[i].size())
      sort(s[i].begin(), s[i].end());
  }
  for (int b = 0; b < SN; ++b) {
    if (s[b].size() == 0) continue;
    int i = s[b][0].a;
    int j = s[b][0].a - 1;

    data.clear();
    for (int k = 0; k < (int)s[b].size(); ++k) {
      int L = s[b][k].a;
      int R = s[b][k].b;

      while (j < R) {
        j++;
        data.update(cost, a[j]);
      }

      while (j > R) {
        data.update(cost, a[j]);
        j--;
      }

      while (i < L) {
        data.update(cost, a[i]);
        i++;
      }

      while (i > L) {
        i--;
        data.update(cost, a[i]);
      }

      ans[s[b][k].id] = data.query();
    }
  }

  for (int i = 0; i < (int)queries.size(); ++i) {
    printf("%d.%d\n", ans[i] / 2, (ans[i] & 1) * 5);
  }
}


// end MO's algorithm


struct edge {
  int to, w;
  edge(int x, int y) : to(x), w(y) {}
};
const int ML = 20;

struct lowest_ca {
  int T[MN], L[MN];
  int P[MN][ML];

  void dfs(const vector<vector<edge>> &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = 0;
      T[root] = -1;
    }
    for (size_t i = 0; i < g[root].size(); ++i) {
      int to = g[root][i].to;
      if (to != pi) {
        T[to] = root;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(const vector<vector<edge> > &g, int root) {
    // g is undirected
    for (int i = 0; i < MN; i++) T[i] = -1;
    for (int i = 0; i < MN; i++) L[i] = 0;

    dfs(g, root);
    int N = g.size(), i, j;

    for (i = 0; i < N; i++) {
      for (j = 0; j < ML; j++) {
        P[i][j] = -1;
      }
    }

    for (i = 0; i < N; i++) {
      P[i][0] = T[i];
    }

    for (j = 1; j < ML; j++)
      for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1) {
          P[i][j] = P[P[i][j - 1]][j - 1];
        }
  }

  int query(int p, int q) {
    int tmp, log, i;

    if (L[p] < L[q])
      tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++) {}
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

  int get_child(int p, int q) { // p is ancestor of q
    if (p == q) return -1;

    int i, log;
    for (log = 1; 1 << log <= L[q]; log++) {}
    log--;

    for (i = log; i >= 0; i--)
      if (L[q] - (1 << i) > L[p]) {
        q = P[q][i];
      }

    assert(P[q][0] == p);
    return q;
  }
};



void flat(vector<vector<edge>> &g, vector<int> &a,
    vector<int> &le, vector<int> &ri, vector<int> &cost,
    int node, int pi, int &ts, int w) {

  cost[node] = w;
  le[node] = ts;
  a[ts] = node;
  ts++;
  for (auto e : g[node]) {
    if (e.to == pi) continue;
    flat(g, a, le, ri, cost, e.to, node, ts, e.w);
  }
  ri[node] = ts;
  a[ts] = node;
  ts++;
}

lowest_ca lca_tree;

void solve() {
  int n;
  cin >> n;
  vector<vector<edge>> g(n);
  for (int i = 0; i < (n - 1); i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  lca_tree.init(g, 0);

  vector<int> a(2 * n), le(n), ri(n), cost(n);
  int ts = 0;
  flat(g, a, le, ri, cost, 0, -1, ts, 0);

  int q; cin >> q;
  vector<query> queries(q);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    int lca = lca_tree.query(u, v);
    if (le[u] > le[v])
      swap(u, v);
    queries[i].id = i;
    queries[i].lca = lca;
    queries[i].u = u;
    queries[i].v = v;
    if (lca == u) {
      queries[i].a = le[u] + 1;
      queries[i].b = le[v];
    } else {
      queries[i].a = ri[u];
      queries[i].b = le[v];
    }
  }
  solve_mo(queries, a, le, cost);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
