#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int n, l, r, ql, qr;
const int MN = 1e5 + 100;
long long a[MN];
long long sl[MN], sr[MN];

int main() {
  while (cin >> n >> l >> r >> ql >> qr) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sr[i] = sl[i + 1] = a[i];
      sl[i + 1] += sl[i];
    }
    for (int i = n - 2; i >= 0; --i)
      sr[i] += sr[i + 1];
    long long best = 1LL << 60;
    for (int i = 0; i <= n; ++i) {
      long long cost = sl[i] * l + sr[i] * r;
      if (i > n - i) cost += (2 * i - n - 1) * ql;
      if (n - i > i) cost += (n - 2 * i - 1) * qr;
      best = min(best, cost);
    }
    cout << best << endl;
  }
  return 0;
}
