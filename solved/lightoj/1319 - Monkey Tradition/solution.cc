using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long mod_pow(long long b, long long e, long long mod) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

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


/**
 * Chinese remainder theorem.
 * Find z such that  z % x[i] = a[i] for all i.
 * if x[i] is not prime, use inv_mod instead of mod_pow to compute
 * the modular inverse.
 * */
long long crt(vector<long long> &a, vector<long long> &x) {
  long long z = 0;
  long long n = 1;
  for (int i = 0; i < x.size(); ++i)
    n *= x[i];

  for (int i = 0; i < a.size(); ++i) {
    long long tmp = (a[i] * (n / x[i])) % n;
    // tmp = (tmp *  mod_pow(n / x[i], x[i] - 2, x[i]) ) % n; // Surprisingly this causes overflow :O
    tmp = (tmp * mod_inv(n / x[i], x[i])) % n;
    z = (z + tmp) % n;
  }

  return (z + n) % n;

}

void solve() {
  int n;
  cin >> n;
  vector<long long> p(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> r[i];
  }

  printf("%lld\n", crt(r, p));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
