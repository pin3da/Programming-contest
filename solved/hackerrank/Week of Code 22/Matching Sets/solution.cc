#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; ++i)
      cin >> x[i];
    for (int i = 0; i < n; ++i)
      cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long p = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += llabs(y[i] - x[i]);
      p -= y[i] - x[i];
    }

    if (p == 0) {
      cout << (ans >> 1) << endl;
#ifdef DEBUG
      int iter = 66;
      while (iter--) {
        long long p = 0;
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
          cur += llabs(y[i] - x[i]);
          p -= y[i] - x[i];
        }
        assert(cur >= ans);
      }
#endif
    }
    else
      cout << -1 << endl;
  }

  return 0;
}
