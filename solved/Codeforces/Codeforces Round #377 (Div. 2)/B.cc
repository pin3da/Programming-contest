#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << (x) << endl

const int MN = 512;
int a[MN];

int n, k;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] + a[i - 1] < k) {
        ans += k - a[i] - a[i - 1];
        a[i] += k - a[i] - a[i - 1];
      }
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
