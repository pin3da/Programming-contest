#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n, m;
  while (cin >> n >> m) {
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int ans = 0;
    for (int i = 1; i < 1000; ++i) {
      int ok = true;
      for (int j = 0; j < n; ++j)
        ok &= ((i % a[j]) == 0);
      for (int j = 0; j < m; ++j)
        ok &= ((b[j] % i) == 0);

      if (ok)
        ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
