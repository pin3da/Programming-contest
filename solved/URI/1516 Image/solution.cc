#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    vector<string> a(n);
    for (auto &i : a) cin >> i;
    int x, y; cin >> x >> y;
    x /= n, y /= m;
    for (int i = 0; i < n; ++i) {
      for (int ii = 0; ii < x; ++ii) {
        for (int j = 0; j < m; ++j)
          for (int jj = 0; jj < y; ++jj)
            cout << a[i][j];
        cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
