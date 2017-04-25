// http://codeforces.com/contest/711/problem/B

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

int check(vector<vector<long long> > &g, long long t) {
  int n = g.size();
  long long x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    long long a = 0, b = 0;
    for (int j = 0; j < n; ++j) {
      a += g[i][j];
      b += g[j][i];
    }

    if ((a != t) || (b != t)) return false;
    x += g[i][i];
    y += g[i][n - 1 - i];
  }
  if ((x != t) || (y != t)) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 1) {
      cout << 9 << endl;
      exit(0);
    }
    vector<vector<long long> > g(n, vector<long long>(n));
    int x, y;
    for (int i = 0; i < n; ++i)
      for (int j =  0; j < n; ++j) {
        cin >> g[i][j];
        if (!g[i][j]) {
          x = i; y = j;
        }
      }

    long long target = 0;
    for (int i = 0; i < n; ++i) {
      int nonz = true;
      long long acc = 0;
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == 0) nonz = false;
        acc += g[i][j];
      }

      if (nonz) {
        target = acc;
        break;
      }

      nonz = true;
      acc = 0;
      for (int j = 0; j < n; ++j) {
        if (g[j][i] == 0) nonz = false;
        acc += g[j][i];
      }

      if (nonz) {
        target = acc;
        break;
      }
    }

    long long ot = target;
    for (int i = 0; i < n; ++i) {
      ot -= g[x][i];
    }
    g[x][y] = ot;
    if ((ot > 0) && check(g, target)) {
      cout << ot << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
