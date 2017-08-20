#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MN = 100111;
const int ML = 20;

struct edge {
  int u, v, id;
  edge(int a, int b, int i) : u(a), v(b), id(i) {}
};

map<int, int> inv[MN]; // id of the edge
void add_edge(vector<vector<edge>> &g, int u, int v) {
  int id_u_v = g[u].size();
  int id_v_u = g[v].size();
  inv[u][v] = id_u_v;
  inv[v][u] = id_v_u;
  g[u].emplace_back(u, v, id_v_u); // id del padre en el hijo
  g[v].emplace_back(v, u, id_u_v); // id del padre en el hijo
}


struct lowest_ca {
  int T[MN], L[MN];
  int P[MN][ML];

  void dfs(const vector<vector<edge>> &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = 0;
      T[root] = -1;
    }
    for (size_t i = 0; i < g[root].size(); ++i) {
      int to = g[root][i].v;
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

lowest_ca tree;

int get_id(int q, int c) {
  int lca = tree.query(q, c);
  int parent = tree.P[q][0];
  if (lca == q) {
    parent = tree.get_child(q, c);
  }
  // cout << "get id " << q << " with capital " << c << " : " << parent << endl;
  if (parent == -1) return -1;
  return inv[q][parent];
}

struct state {
  bool seen;
  int missing;
  int cur_total;
  vector<int> partial;

  state() {
    clear();
  }

  void clear() {
    seen = false;
    cur_total = 0;
    missing = 0;
  }
};

state dp[MN];

int go(vector<vector<edge>> &g, int node, int id_p) {
  state &s = dp[node];

  // cout << "empieza " << node << " con id " << id_p << endl;
  if (!s.seen) {
    int ans = 1;
    s.partial.assign(g[node].size(), 0);
    for (int i = 0; i < (int)g[node].size(); i++) {
      edge e = g[node][i];
      if (i != id_p) {
        // cout << "desde " << node << " hasta " << e.v << " con id " << e.id << endl;
        int tmp = go(g, e.v, e.id); // id del padre en el hijo
        ans += tmp;
        s.partial[i] = tmp;
      }
    }
    s.missing = id_p;
    s.cur_total = ans;
    s.seen = true;
    return ans;
  } else {
    if (s.missing == -1) { // ya vi todos
      int other = 0;
      if (id_p != -1) other = s.partial[id_p];
      return s.cur_total - other;
    }
    if (s.missing == id_p) {
      return s.cur_total;
    }
    edge to = g[node][s.missing];
    int t = go(g, to.v, to.id);
    s.partial[s.missing] = t;
    s.missing = -1;
    s.cur_total += t;
    int other = 0;
    if (id_p != -1) other = s.partial[id_p];
    return s.cur_total - other;
  }
}

void solve() {
  int n, q, cap;
  cin >> n >> q >> cap;
  cap--;

  for (int i = 0; i < (int)n + 1; i++) inv[i].clear();
  for (int i = 0; i < (int)n + 1; i++) dp[i].clear();

  vector<vector<edge>> g(n);
  for (int i = 0; i < (int)(n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    add_edge(g, u, v);
  }
  tree.init(g, 0);

  while (q--) {
    int s, u;
    cin >> s >> u;
    u--;
    if (s == 0) {
      cap = u;
    } else {
      int id_edge = get_id(u, cap);
      cout << go(g, u, id_edge) << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ":" << endl;
    solve();
  }
}
