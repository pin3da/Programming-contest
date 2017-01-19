#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m;
  while (cin >> n >> m && (n + m)) {
    int total = 0;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
      int t;
      for (int j = 0; j + 1 < m; ++j)
        cin >> t;
      cin >> t;
      d[i] = t;
      total += t;
    }
    for (int i = 0; i < n; ++i) {
      int g = __gcd(d[i], total);
      cout << d[i] / g << " / " << total / g << endl;
    }
  }

  return 0;
}
