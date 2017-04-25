// http://codeforces.com/contest/343/problem/C

#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl;

using namespace std;

const int MN = 1e5 + 100;

long long a[MN], b[MN];
const long long inf = 1LL << 60;
int n, m;

bool f(long long t) {
  int j = 0;
  for (int i = 0; i < n && j < m; ++i) {
    if (a[i] <= b[j]) {
      j = upper_bound(b, b + m, a[i] + t) - b;
    } else {
      long long d1 = a[i] - b[j];
      if (t < d1) continue;
      long long d2 = t - d1;
      long long best = max(d2 / 2, t - 2 * d1);
      int k = upper_bound(b, b + m, a[i] + best) - b;
      if (k > j) j = k;
    }
  }
  return j == m;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int j = 0; j < m; ++j)
      cin >> b[j];
    long long lo = 0, hi = 1000000LL * 1000000LL;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      if (f(mid)) hi = mid;
      else lo = mid + 1;
    }
    cout << lo << endl;
  }
  return 0;
}
