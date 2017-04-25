// http://codeforces.com/contest/287/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#ifndef BMO
#define endl '\n'
#define _io ios_base::sync_with_stdio(false);cin.tie(NULL);
#else
#define _io
#endif

long long f(long long x) {
  return (x * (x + 1)) >> 1;
}

long long solve(long long n, long long k) {
  n--; k--;
  long long lo = 1, hi = k;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (f(k) - f(mid) < n)
      hi = mid;
    else
      lo = mid + 1;
  }
  return 1 + k - lo;
}

int main() { _io
  long long n, k;
  while (cin >> n >> k) {
    if (n == 1) {
      cout << 0 << endl;
      continue;
    }
    long long mmax = ((k * (k - 1)) >> 1) + 1;
    if (n > mmax) {
      cout << - 1 << endl;
      continue;
    }
    if (n <= k) {
      cout << 1 << endl;
      continue;
    }
    long long ans = solve(n, k);
    cout << ans << endl;
  }
  return 0;
}
