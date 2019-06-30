#include <bits/stdc++.h>

using namespace std;

const int BLOCK_SIZE = 350;

struct Graph {
  int N, L, timestamp;
  vector<int> cost, tin, tout, A;
  vector<vector<int>> adj, up;
  Graph(int n) : N(n), L(0), timestamp(0), cost(n), tin(n), tout(n), A(2 * n), adj(n), up(n) { }

  void AddEdge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  void DFS(int node, int parent) {
    tin[node] = timestamp;
    A[timestamp] = node;
    timestamp++;
    up[node][0] = parent;
    for (int i = 1; i <= L; i++) {
      up[node][i] = up[up[node][i-1]][i-1];
    }
    for (auto to : adj[node]) {
      if (to != parent) {
        DFS(to, node);
      }
    }
    tout[node] = timestamp;
    A[timestamp] = node;
    timestamp++;
  }

  bool IsAncestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
  }

  int LCA(int a, int b) {
    if (IsAncestor(a, b)) return a;
    if (IsAncestor(b, a)) return b;
    for (int i = L; i >= 0; i--) {
       if (!IsAncestor(up[a][i], b)) {
        a = up[a][i];
       }
    }
    return up[a][0];
  }

  void PrepareLCA(int root) {
    L = 1;
    while ((1 << L) <= N) {
      L++;
    }
    for (int i = 0; i < N; i++) {
      up[i].resize(L + 1);
    }
    timestamp = 0;
    DFS(root, root);
  }
};


struct Query {
  int idx, l, r, lca;
  bool operator < (const Query& b) const {
    if ((l / BLOCK_SIZE) != (b.l / BLOCK_SIZE)) return l < b.l;
    if ((l / BLOCK_SIZE) & 1) return r > b.r;
    return r < b.r;
  }
};

struct DS {
  vector<int> active, frec;
  int total;
  DS(int n) : active(n), frec(n), total(0) {}
  void Toggle(int idx, vector<int>& A) {
    if (active[idx]) {
      frec[A[idx]]--;
      if (frec[A[idx]] == 0) total--;
    } else {
      if (frec[A[idx]] == 0) total++;
      frec[A[idx]]++;
    }
    active[idx] ^= 1;
  }
  int Query() {
    return total;
  }
};

vector<int> SolveMo(vector<Query>& queries, vector<int>& values, vector<int>& A) {
  vector<int> ans(queries.size());
  sort(queries.begin(), queries.end());
  int i = 0, j = -1; // [i, j)
  DS ds(values.size());
  for (int idx = 0; idx < (int)queries.size(); idx++) {
    const auto& q = queries[idx];
    while (i < q.l) ds.Toggle(A[i++], values);
    while (i > q.l) ds.Toggle(A[--i], values);
    while (j < q.r) ds.Toggle(A[++j], values);
    while (j > q.r)  ds.Toggle(A[j--], values);
    int add_lca = (q.lca != A[q.l]) && (q.lca != A[q.r]);
    if (add_lca) ds.Toggle(q.lca, values);
    ans[q.idx] = ds.Query();
    if (add_lca) ds.Toggle(q.lca, values);
  }
  return ans;
}

void solve() {
  int n, q; 
  cin >> n >> q;
  map<string, int> gen_id;
  vector<int> values(n);
  for (int i = 0; i < n; i++) {
    string id; 
    cin >> id;
    if (gen_id.count(id) == 0) {
      int cur = gen_id.size();
      gen_id[id] = cur;
    }
    values[i] = gen_id[id];
  }

  Graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g.AddEdge(u - 1, v - 1);
  }

  g.PrepareLCA(0);

  vector<Query> queries(q);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    if (g.tin[u] > g.tin[v]) {
      swap(u, v);
    }
    int lca = g.LCA(u, v);
    queries[i].lca = lca;
    queries[i].idx = i;
    if (u == lca) {
      queries[i].l = g.tin[u];
      queries[i].r = g.tin[v];
    } else {
      queries[i].l = g.tout[u];
      queries[i].r = g.tin[v];
    }
  }
  vector<int> ans = SolveMo(queries, values, g.A);
  for (auto it : ans) {
    cout << it << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif
  solve();
  return 0;
}
