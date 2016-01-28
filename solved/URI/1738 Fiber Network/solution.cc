#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  vector<vector<int>> g(n, vector<int> (n, 0));
  int u, v;
  while (cin >> u >> v && (u + v)) {
    u--;v--;
    string line; cin >> line;
    int mask = 0;
    for (int i = 0; i < line.size(); ++i) {
      mask |= (1 << (line[i] - 'a'));
    }
    g[u][v] |= mask;
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        g[i][j] |= g[i][k] & g[k][j];

  while (cin >> u >> v && (u + v)) {
    u--;v--;
    if (g[u][v] == 0)
      cout << "-";
    else
      for (int i = 0; i < 30; ++i)
        if ((g[u][v] >> i) & 1)
          cout << char(i + 'a');
    cout << endl;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n)
    solve(n);
  return 0;
}
