#include <bits/stdc++.h>

using namespace std;

const int MN = 543;

int a[MN][MN];
int b[MN][MN];
int x[MN];
long long ans[MN];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    for (int i = n - 1; i >= 0; --i) {
      cin >> x[i];
      x[i]--;
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        b[i][j] = a[x[i]][x[j]];

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          b[i][j] = min(b[i][j], b[i][k] + b[k][j]);

      ans[n - 1 - k] = 0;
      for (int i = 0; i <= k; ++i)
        for (int j = 0; j < i; ++j)
          ans[n - 1 - k] += b[i][j] + b[j][i];
    }
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
