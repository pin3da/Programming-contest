#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

const long long mod = 1000 * 1000 * 1000 + 7;

void ext_euclid(long long a, long long b, long long &x, long long &y, long long &g) {
  x = 0, y = 1, g = b;
  long long m, n, q, r;
  for (long long u = 1, v = 0; a != 0; g = a, a = r) {
    q = g / a, r = g % a;
    m = x - u * q, n = y - v * q;
    x = u, y = v, u = m, v = n;
  }
}

long long mod_inv(long long n, long long m = mod) {
  long long x, y, gcd;
  ext_euclid(n, m, x, y, gcd);
  if (gcd != 1)
    return 0;
  return (x + m) % m;
}

long long mul(long long x, long long y) {
  long long ans = x * y;
  if (ans >= mod)
    ans %= mod;
  return ans;
}

long long add(long long x, long long y) {
  long long ans = x + y;
  if (ans >= mod)
    ans -= mod;
  return ans;
}

long long sub(long long x, long long y) {
  long long ans = x - y;
  if (ans < 0)
    ans += mod;
  return ans;
}
void add(long long a, long long b,
         long long p, long long q,
         long long &x, long long &y) {

  x = mul(add(mul(p, b), mul(a, q)), mod_inv(mul(q, b)));
  y = mul(sub(mul(q, b), mul(p, a)), mod_inv(mul(q, b)));
}

void solve() {
  long long p, q, n;
  cin >> p >> q >> n;

  long long num = 0, den = 1;
  while (n > 0) {
    if (n & 1) {
      add(num, den, p, q, num, den);
    }
    add(p, q, p, q, p, q);
    n >>= 1;
  }
  // D(num);D(den);
  cout << mul(num, mod_inv(den)) << endl;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
