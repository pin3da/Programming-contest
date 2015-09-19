using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<vector<ll> > d(n, vector<ll>(n));
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
      for (int j = 0; j < i; ++j) {
        long long a = x[i] - x[j];
        long long b = y[i] - y[j];
        d[i][j] = d[j][i]  = a * a + b * b;
      }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      sort(d[i].begin(), d[i].end());
      int accum = 1;
      for (int j = 1; j < n; ++j) {
        if (d[i][j] != d[i][j - 1]) {
          ans += (accum * (accum - 1)) >> 1;
          accum = 1;
        } else
          accum++;
      }
      ans += (accum * (accum - 1)) >> 1;
    }

    cout << ans << endl;
  }
  return 0;
}
