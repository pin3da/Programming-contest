#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct person {
  int c, k;
  person() {}
};

const long long mod = 1e9 + 7;

inline
long long add(long long x, int y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

void dfs(vector<vector<int>> &g, vector<person> &p, vector<int> &ans,
          map<pair<int, int>, int> &tree, int node) {

  person cur = p[node];
  pair<int, int> st1(cur.c, cur.k);
  pair<int, int> st2(cur.c, cur.k - 1);
  if (cur.k == 0) {
    tree[st1] = add(tree[st1], 1);
    ans[node] = 1;
    for (auto to : g[node])
      dfs(g, p, ans, tree, to);
    return;
  }
  if (tree.count({cur.c, cur.k - 1})) {
    ans[node] -= tree[st2];
    if (ans[node] < 0) ans[node] += mod;
  }
  for (auto to : g[node]) {
    dfs(g, p, ans, tree, to);
  }

  if (tree.count({cur.c, cur.k - 1}))
    ans[node] = add(ans[node], tree[st2]);
  ans[node] = add(ans[node], mod);
  tree[st1] = add(tree[st1], ans[node]);
}

void solve() {
  int n, x; cin >> n >> x;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int pi; cin >> pi;
    g[pi].push_back(i);
  }
  vector<person> all(n);
  for (auto &it: all)  cin >> it.c;
  for (auto &it: all)  cin >> it.k;
  vector<int> ans(n);
  map<pair<int, int>, int> tree;

  dfs(g, all, ans, tree, 0);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
