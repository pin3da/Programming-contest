#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long ans;
void dfs(vector<vector<int>> &g, vector<int> &col, vector<int> &up,
    vector<int> &down, int node) {

  long long above = up[col[node]];
  up[col[node]]++;
  down[col[node]]++;
  long long below = -down[col[node]];
  for (auto to : g[node]) {
    dfs(g, col, up, down, to);
  }
  below += down[col[node]];
  up[col[node]]--;

  // cout << "node " << node << " ab " << above << " bel "  << below << endl;
  ans += above * below;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int pi; cin >> pi;
    g[pi].push_back(i);
  }
  vector<int> c(n);
  for (auto &i: c) cin >> i;
  vector<int> up(n), down(n);
  ans = 0;
  dfs(g, c, up, down, 0);
  cout << ans << endl;

  for (int i = 0; i < q; ++i) {
    int x; cin >> x;
    c[i % n] = (n + ans + x) % n;
    ans = 0;
    dfs(g, c, up, down, 0);
    cout << ans << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc = 1;
  while (tc--) solve();
  return 0;
}
