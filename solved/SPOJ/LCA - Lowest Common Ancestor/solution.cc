#include <bits/stdc++.h>

using namespace std;

struct LCA {

  vector<int> height, euler, first, segtree;
  vector<bool> visited;
  int n;

  LCA(vector<vector<int>> &g, int root = 0) {
    n = g.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);
    dfs(g, root);
    int m = euler.size();
    segtree.resize(m * 4 + 10);
    build(1, 0, m - 1);
  }

  void dfs(vector<vector<int>> &g, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : g[node]) {
      if (!visited[to]) {
        dfs(g, to, h + 1);
        euler.push_back(node);
      }
    }
  }

  void build(int node, int b, int e) {
    if (b == e) {
      segtree[node] = euler[b];
    } else {
      int mid = (b + e) / 2;
      build(node << 1, b, mid);
      build(node << 1 | 1, mid + 1, e);
      int l = segtree[node << 1], r = segtree[node << 1 | 1];
      segtree[node] = (height[l] < height[r]) ? l : r;
    }
  }

  int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L)
      return -1;
    if (b >= L && e <= R)
      return segtree[node];
    int mid = (b + e) >> 1;

    int left = query(node << 1, b, mid, L, R),
        right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
  }

  int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right)
      swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int m; cin >> m;
    while (m--) {
      int tmp; cin >> tmp;
      g[i].emplace_back(tmp - 1);
      g[tmp - 1].emplace_back(i);
    }
  }
  int q;
  cin >> q;
  LCA lca(g);
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
