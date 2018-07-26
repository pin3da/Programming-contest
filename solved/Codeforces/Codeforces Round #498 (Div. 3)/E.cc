#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void dfs(vector<vector<int>> &g, vector<int> &path, vector<int> &pos, vector<int> &size, int node) {
  pos[node] = path.size();
  path.push_back(node);
  size[node] = 1;
  for (auto to : g[node]) {
    dfs(g, path, pos, size, to);
    size[node] += size[to];
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p; cin >> p;
    g[p - 1].emplace_back(i);
  }

  vector<int> path, pos(n), size(n);
  dfs(g, path, pos, size, 0);

  while (q--) {
    int node, k;
    cin >> node >> k;
    node--;
    if (size[node] < k) cout << -1 << endl;
    else cout << path[pos[node] + k - 1] + 1 << endl;
  }
  return 0;
}
