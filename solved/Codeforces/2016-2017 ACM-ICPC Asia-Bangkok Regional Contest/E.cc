#include<bits/stdc++.h>
// #define endl '\n'

using namespace std;

const int MN = 5 * 100000 + 100;
const int SN = 708;

struct edge {
  int to, w;
  edge(int x, int y) : to(x), w(y) {}
};

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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


struct my_int {
  int val, id;
  my_int(int a, int b) : val(a), id(b) {}
  bool operator<(const my_int &a) const {
    if (val == a.val) return id < a.id;
    return val < a.id;
  }
};

typedef tree<my_int,null_type,less<my_int>,//key,mapped type, comparator
rb_tree_tag,tree_order_statistics_node_update> set_t;

struct DS {

  set_t data;

  void clear() {
    data.clear();
  }
  void insert(int x, int i) {
    data.insert(my_int(x, i));
  }
  void erase(int x, int i) {
    data.erase(my_int(x, i));
  }
  long long query() {
    int len = data.size();
    if (len & 1) {
      int k = (len) >> 1;
      return data.find_by_order(k)-> val * 2;
    }
    int k = (len) >> 1;
    return data.find_by_order(k)-> val + data.find_by_order(k - 1)-> val;
  }
};

DS data;

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

lowest_ca lca_tree;

void solve_mo(vector<query> &queries, vector<int> &a, vector<int> &le) {
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
        data.insert(a[j], j);
      }

      while (j > R) {
        data.erase(a[j], j);
        j--;
      }

      while (i < L) {
        data.erase(a[i], i);
        i++;
      }

      while (i > L) {
        i--;
        data.insert(a[i], i);
      }

      if (s[b][k].lca == s[b][k].a) {
        int id = le[s[b][k].a];
        data.insert(a[id], id);
      }
      ans[s[b][k].id] = data.query();
    }
  }

  for (int i = 0; i < (int)queries.size(); ++i) {
    cout << ans[i] << endl;
  }
}


void flat(vector<vector<edge>> &g, vector<int> &a,
      vector<int> &le, vector<int> &ri, int node, int pi, int &ts) {

  le[node] = ts;
  a[ts] = node;
  ts++;
  for (auto e : g[node]) {
    if (e.to == pi) continue;
    flat(g, a, le, ri, e.to, node, ts);
  }
  ri[node] = ts;
  a[ts] = node;
  ts++;
}

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

  vector<int> a(2 * n), le(n), ri(n);
  int ts = 0;
  flat(g, a, le, ri, 0, -1, ts);
  int q; cin >> q;
  vector<query> queries(q);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int c = lca_tree.query(a, b);
    if (le[a] > le[b])
      swap(a, b);
    queries[i].lca = c;
    queries[i].u = a;
    queries[i].v = b;
    if (c == a) {
      queries[i].a = le[a];
      queries[i].b = le[b];
    } else {
      queries[i].a = ri[a];
      queries[i].b = le[b];
    }
  }

  solve_mo(queries, a, le);
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
