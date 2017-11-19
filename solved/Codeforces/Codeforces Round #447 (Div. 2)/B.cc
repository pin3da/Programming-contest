#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool valid(vector<vector<int>> &g, int k) {
  int ok = true;
  int n = g.size(), m = g[0].size();
  for (int i = 0; ok && i < n; i++) {
    int cur = 1;
    for (int j = 0; ok && j < m; j++) {
      cur *= g[i][j];
    }
    ok &= (cur == k);
  }

  for (int j = 0; ok && j < m; j++) {
    int cur = 1;
    for (int i = 0; ok && i < n; i++) {
      cur *= g[i][j];
    }
    ok &= (cur == k);
  }

  return ok;
}

void print(vector<vector<int>> &g) {
  int n = g.size(), m = g[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m, k;
  while (cin >> n >> m >> k) {
    int top = 1 << (n * m);
    int ans = 0;
    for (int mask = 0; mask < top; mask++) {
      vector<vector<int>> g(n, vector<int>(m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          int id = i * n + j;
          if ((mask >> id) & 1) g[i][j] = -1;
          else g[i][j] = 1;
        }
        if (valid(g, k)) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
