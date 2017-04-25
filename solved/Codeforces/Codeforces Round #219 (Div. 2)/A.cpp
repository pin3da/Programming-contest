// http://codeforces.com/contest/373/problem/A

#include <bits/stdc++.h>

using namespace std;

char g[4][4];
int f[11];

int main() {
  int k;
  while (cin >> k) {
    memset(f, 0, sizeof f);
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        cin >> g[i][j];
        if (g[i][j] != '.') f[g[i][j] - '0']++;
      }

    int ok = true;
    for (int i = 0; i < 10; ++i)
      ok &= f[i] <= (k + k);

    puts(ok ? "YES" : "NO");

  }
  return 0;
}
;
}
