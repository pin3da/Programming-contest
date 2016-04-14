#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, p;
  while (cin >> m >> n >> p && (n + m + p)) {
    int q;
    long long ans = 0;
    vector<vector<int>> g(m, vector<int> (n));
    int pos = -1;
    int cur = 0;
    while (p--) {
      cin >> q;
      pos += q;
      int x = cur + (pos / n),
          y = pos % n;
      g[x][y] = 1;
      cur = x + 1;
      pos = -1;
    }

    for (int i = 0; i < m; ++i) {
      if (g[i][0]) ans++;
      for (int j = 1; j < n; ++j) {
        g[i][j] += g[i][j - 1];
        if (g[i][j])
          ans++;
      }
    }

    cout << "Lights: ";
    cout << ans << endl;
  }

  return 0;
}
