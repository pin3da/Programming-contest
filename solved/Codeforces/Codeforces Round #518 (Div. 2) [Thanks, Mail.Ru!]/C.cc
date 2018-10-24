#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[i].emplace_back(i, i);
  }

  vector<pair<int, int>> input;
  int row = n + 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ans[u].emplace_back(row, u);
    ans[v].emplace_back(row, v);
    row++;
  }


  for (int i = 1; i <= n; i++) {
    cout << ans[i].size() << endl;
    for (auto it : ans[i]) {
      cout << it.first << " " << it.second << endl;
    }
  }
  return 0;
}
