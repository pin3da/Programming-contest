#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1e9 + 100;

long long tri(long long x) {
  return (x * (x + 1)) >> 1;
}

long long fun(long long t, long long side) {
  if (t > side) {
    long long diff = t - side;
    return tri(t) - tri(diff);
  } else {
    return tri(t);
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  long long n, m, k;
  cin >> n >> m >> k;

  long long left = k - 1;
  long long right = n - k;

  m -= n;
  if (m == 0) {
    cout << 1 << endl;
    return 0;
  }

  long long lo = 0, hi = MN;

  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    long long a = fun(mid - 1, left);
    long long b = fun(mid - 1, right);
    if (a + b + mid > m)
      hi = mid - 1;
    else
      lo = mid;
  }

  cout << lo + 1 << endl;
  return 0;
}
