#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << (x) << endl

const int MN = 512;
int a[MN];
int b[MN];

int n, k;

bool valid() {
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] + a[i + 1] < k) return false;
  }
  return true;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    if (n <= 2) {
      int f = k - a[0];
      if (n == 2)
        f -= a[1];

      f = max(0, f);
      a[0] += f;
      cout << f << endl;
      for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
      }
      cout << endl;
      continue;
    }

    long long ans = 0;
    while (!valid()) {
      int id = -1;
      for (int i = 1; i + 1 < n; ++i) {
        if (a[i] + a[i - 1] < k || a[i] + a[i + 1] < k) {
          id = i;
          break;
        }
      }
      int f = 1000;
      if (id > 0)
        f = min(f, a[id] + a[id - 1]);
      if (id + 1 < n)
        f = min(f, a[id] + a[id + 1]);
      if (k - f > 0)
        ans += k - f;
      a[id] += max(0, k - f);
    }
    cout << ans << endl;

    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}
