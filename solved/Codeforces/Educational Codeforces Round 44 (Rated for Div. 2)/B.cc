#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char> (m));
  for (auto &it : g)
    for (auto &c : it)
      cin >> c;

  vector<int> state(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      state[j] += (g[i][j] == '1');
    }
  }

  for (int i = 0; i < n; i++) {
    int ok = true;
    for (int j = 0; j < m; j++) {
      state[j] -= (g[i][j] == '1');
      ok &= (state[j] > 0);
      state[j] += (g[i][j] == '1');
    }
    if (ok) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

