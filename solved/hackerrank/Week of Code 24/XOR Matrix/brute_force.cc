#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 100;
int a[1001][MN];
int b[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      cin >> a[0][i];

    for (int k = 1; k < m; ++k) {
      for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        a[k][i] = a[k - 1][i] ^ a[k - 1][j];
      }
    }

    memcpy(b, a[m - 1], sizeof b);
    // sort(b, b + n);
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << b[i];
    }
    cout << endl;
  }

  return 0;
}
