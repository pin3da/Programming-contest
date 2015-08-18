using namespace std;
#include <bits/stdc++.h>

int ans;
int dfs(deque<deque<int> > &g, deque<int> &b, int node) {

  int cur = b[node] - 1;
  for (int i = 0; i < g[node].size(); ++i)
    cur += dfs(g, b, g[node][i]);
  ans += abs(cur);
  return cur;
}


void solve() {
  int n;
  cin >> n;
  int v, d, u;
  deque<deque<int> > g(n);
  deque<int> boys(n), in(n);
  for (int i = 0; i < n; ++i) {
    cin >> v; v--;
    cin >> boys[v] >> d;
    for (int j = 0; j < d; ++j) {
      cin >> u;
      u--;
      g[v].push_back(u);
      in[u]++;
    }
  }

  ans = 0;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0)
      assert(dfs(g, boys, i) == 0);
  }
  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
