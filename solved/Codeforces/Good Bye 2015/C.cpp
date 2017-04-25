// http://codeforces.com/contest/611/problem/C

using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

void solve(int n, int m) {
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j< m; ++j)
      cin >> g[i][j];
  }

  vector<vector<int>> h(n, vector<int>(m));
  vector<vector<int>> v(n, vector<int>(m));

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j< m; ++j) {
      v[i][j] = g[i][j] == '.' && g[i - 1][j] == '.';
      v[i][j] += v[i - 1][j];
    }
  }

  for (int j = 1; j< m; ++j) {
    for (int i = 0; i < n; ++i) {
      h[i][j] = g[i][j] == '.' && g[i][j - 1] == '.';
      h[i][j] += h[i][j - 1];
    }
  }

  int q; cin >> q;
  int a, b, c, d;
  while (q--) {
    cin >> a >> b >> c >> d;
    a--;b--;c--;d--;
    long long ans = 0;
    for (int i = a; i <= c; ++i) {
      ans += h[i][d] - h[i][b];
    }
    for (int j = b; j <= d; ++j) {
      ans += v[c][j] - v[a][j];
    }
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    solve(n, m);
  }
  return 0;
}
