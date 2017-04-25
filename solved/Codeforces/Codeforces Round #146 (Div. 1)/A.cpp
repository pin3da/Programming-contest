// http://codeforces.com/contest/235/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  while (cin >> n) {
    long long ans = n;
    for (long long a = max(1ll, n - 4); a <= n; ++a)
      for (long long b = a; b <= n; ++b)
        for (long long c = b; c <= n; ++c) {
          long long t = a / __gcd(a, b) * b;
          t = t / __gcd(t, c) * c;
          ans = max(ans, t);
        }

    cout << ans << endl;
  }

  return 0;
}

