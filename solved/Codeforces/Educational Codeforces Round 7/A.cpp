// http://codeforces.com/contest/622/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
long long f(long long x) {
  return (x * (x + 1)) >> 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  while (cin >> n) {
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    long long lo = 1, hi = 100000000LL;
    while (lo < hi) {
      long long mid = (lo + hi + 1) >> 1;
      if (f(mid) < n)
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << n - f(lo) << endl;
  }
  return 0;
}
