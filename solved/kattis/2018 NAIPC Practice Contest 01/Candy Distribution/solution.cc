#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void ext_euclid(long long a, long long b, long long &x, long long &y, long long &g) {
  x = 0, y = 1, g = b;
  long long m, n, q, r;
  for (long long u = 1, v = 0; a != 0; g = a, a = r) {
    q = g / a, r = g % a;
    m = x - u * q, n = y - v * q;
    x = u, y = v, u = m, v = n;
  }
}

long long mod_inv(long long n, long long m) {
  long long x, y, gcd;
  ext_euclid(n, m, x, y, gcd);
  if (gcd != 1)
    return 0;
  return (x + m) % m;
}

const int MMAX = 1e9;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc;
  cin >> tc;
  while (tc--) {
    long long k, c;
    cin >> k >> c;
    if (k == 1) {
      if (c > 1) {
        cout << "1" << endl;
      } else {
        cout << "2" << endl;
      }
    } else if (c == 1) {
      cout << k + 1 << endl;
    } else {
      long long g = __gcd(k, c);
      if (g != 1) {
        cout << "IMPOSSIBLE" << endl;
      } else {
        cout << mod_inv(c, k) << endl;
      }
    }
  }
  return 0;
}
