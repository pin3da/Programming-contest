#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


const int MN = 333;
int memo[MN][MN];

int max_down(vector<vector<int>> &g, int i, int j) {
  if (memo[i][j] != -1) return memo[i][j];
  int ans = 0;
  for (int k = i; k < int(g.size()) && g[k][j] == 1; k++) {
    ans++;
  }
  return memo[i][j] = ans;
}

void solve() {
  int n, m;
  read(n, m);
  vector<vector<int>> g(n, vector<int>(m));

  for (auto &it : g) for (auto &i : it) cin >> i;

  memset(memo, -1, sizeof memo);

  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 1) {
        for (int k = j + 1; k < m && g[i][k] == 1; k++) {
          if (max_down(g, i, k) > 1)
            best = max(best, k - j + max_down(g, i, k));
        }
      }
    }
  }

  cout << best << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

