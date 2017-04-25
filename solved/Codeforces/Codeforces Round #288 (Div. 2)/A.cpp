// http://codeforces.com/contest/508/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

bool f(vector<vector<bool> > &g, int x, int y) {
  if (x >= 0 and x < g.size() and y >= 0 and y < g[0].size())
    return g[x][y];
  return false;
}

int main() { ___
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool> > g(n, vector<bool>(m, false));
  int x, y;
  for (int i = 0; i < k; ++i) {
    cin >> x >> y;
    x--; y--;
    g[x][y] = true;
    if (f(g, x - 1, y) and f(g, x - 1, y + 1) and f(g, x, y + 1)) {
      cout << i + 1 << endl;
      return 0;
    }
    if (f(g, x - 1, y - 1) and f(g, x - 1, y) and f(g, x, y -1)) {
      cout << i + 1 << endl;
      return 0;
    }
    if (f(g, x, y - 1) and f(g, x + 1, y - 1) and f(g, x + 1, y)) {
      cout << i + 1 << endl;
      return 0;
    }
    if (f(g, x, y + 1) and f(g, x + 1, y + 1) and f(g, x + 1, y)) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << 0 << endl;

  return 0;
}
