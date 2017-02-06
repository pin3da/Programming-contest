#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  long long a, b;
  cin >> a >> b;
  long long lo = 1, hi = 1e9;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    long long x = mid * b - mid * a;
    if (x >= a)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo + 1 << endl;

  return 0;
}
