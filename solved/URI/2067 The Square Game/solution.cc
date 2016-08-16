#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 222;
int z[MN][MN];

int n, m;
void compute() {
  for (int i = 1; i < n + 1; ++i)
    for (int j = 1; j < m + 1; ++j)
      z[i][j] += z[i - 1][j] + z[i][j - 1] - z[i - 1][j - 1];
}

int query(int x, int y, int a, int b) {
  return z[a][b] - z[a][y - 1] - z[x - 1][b] + z[x - 1][y - 1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      int t; cin >> t;
      z[i][j] = t == 0;
    }
  }
  compute();
  int q; cin >> q;
  while (q--) {
    int s; cin >> s;
    int seen = 0;
    s--;
    for (int i = 1; i < n + 1 && !seen; ++i) {
      if (i + s < n + 1)
        for (int j = 1; j < m + 1 && !seen; ++j) {
          if (j + s < m + 1) {
            seen = query(i, j, i + s, j + s) == 0;
          }
        }
    }
    puts(seen ? "yes" : "no");
  }

  return 0;
}
