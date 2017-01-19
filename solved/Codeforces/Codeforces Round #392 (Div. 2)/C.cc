#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long ans[123][123];

int dy[] = {1, -1};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m;
  long long k;
  int x, y;
  cin >> n >> m >> k >> x >> y;
  long long magic;
  if (n < 3) {
    magic = n * m;
  } else {
    magic = n * m + (n - 2) * m;
  }
  long long W = k;
  long long base = k / magic;
  k %= magic;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i != 0 && i != (n - 1))
        ans[i][j] = 2 * base;
      else
        ans[i][j] = base;
    }
  }

  int i = 0, j = 0;
  int side = 0;
  while (k--) {
    ans[i][j]++;
    j++;
    if (j == m) {
      j = 0;
      i += dy[side];
      if (i == n || (i == -1)) {
        side ^= 1;
        i += dy[side];
        i += dy[side];
      }
    }
  }

  long long mmin = W + 100, mmax = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      mmin = min(mmin, ans[i][j]);
      mmax = max(mmax, ans[i][j]);
    }
  }
  cout << mmax << ' ' << mmin << ' ' << ans[x - 1][y - 1] << endl;
  return 0;
}
