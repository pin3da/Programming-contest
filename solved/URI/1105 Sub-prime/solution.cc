#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) cin >> g[i][i];
    int a, b, c;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      a--;b--;
      g[a][b] -= c;
      g[b][a] += c;
    }
    int ok = true;
    for (int i = 0; i < n; ++i)
      ok &= accumulate(g[i].begin(), g[i].end(), 0) >= 0;
    cout << (ok ? 'S' : 'N') << endl;
  }
  return 0;
}
