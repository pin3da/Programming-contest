#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &it : g) cin >> it;
  vector<int> ans(n + m - 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '1') {
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < m; y++) {
            if (g[x][y] == '1') {
              ans[abs(x - i) + abs(y - j)]++;
            }
          }
        }
      }
    }
  }

  for (int i = 1; i < int(ans.size()); i++) {
    if (i > 1) cout << " ";
    cout << (ans[i] / 2);
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
