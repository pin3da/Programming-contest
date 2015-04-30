using namespace std;
#include <bits/stdc++.h>

const int MN = 1001;
struct ht {
  int _s[(MN + 10) >> 5];
  int len;
  void set(int id) {
    len++;
    _s[id >> 5] |= (1LL << (id & 31));
  }
  bool is_set(int id) {
    return _s[id >> 5] & (1LL << (id & 31));
  }
};

ht seen[MN];

void dfs(vector<vector<int> > &g, int node, int cur) {
  if (seen[node].is_set(cur))
    return;

  seen[node].set(cur);
  for (int i = 0; i < g[node].size(); ++i) {
    if (seen[g[node][i]].is_set(cur) == 0)
      dfs(g, g[node][i], cur);
  }
}

void solve() {
  int k, n, m;
  memset(seen, 0, sizeof seen);
  cin >> k >> n >> m;
  vector<int> p(k);
  for (int i = 0; i < k; ++i)
    cin >> p[i];

  vector<vector<int> > g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }

  for (int i = 0; i < k; ++i)
    dfs(g, p[i] - 1, i);


  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (seen[i].len == k)
      ans++;

  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
