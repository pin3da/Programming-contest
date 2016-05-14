#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long f(long long x) {
  return (x * (x + 1)) >> 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    long long lo = 0, hi = 2 * 1000 * 1000 * 1000 + 100;
    while (lo < hi) {
      long long mid = (lo + hi + 1) >> 1;
      if (f(mid) <= n)
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << lo << endl;
  }
  return 0;
}
