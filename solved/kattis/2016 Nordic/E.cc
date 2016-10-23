#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

long long mod_pow(long long b, long long e, long long m) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return ans;
}

const int MN = 100000 + 10;
long long primes[MN];
bool sieve[MN];

long long totient(long long n) {
  if (n == 1) return 0;
  long long ans = n;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      while ((n % primes[i]) == 0) n /= primes[i];
      ans -= ans / primes[i];
    }
  }
  if (n > 1) {
    ans -= ans / n;
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
 * */
long long crt(vector<long long> &a, vector<long long> &x) {
  long long z = 0;
  long long n = 1;
  for (int i = 0; i < (int)x.size(); ++i)
    n *= x[i];

  for (int i = 0; i < (int)a.size(); ++i) {
    long long tmp = (a[i] * (n / x[i])) % n;
    tmp = (tmp * mod_inv(n / x[i], x[i])) % n;
    z = (z + tmp) % n;
  }

  return (z + n) % n;
}

vector<long long> factorize(long long n) {
  vector<long long> ans;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      long long pi = 1;
      while ((n % primes[i]) == 0) {
        n /= primes[i];
        pi *= primes[i];
      }
      ans.push_back(pi);
    }
  }
  if (n > 1) {
    ans.push_back(n);
  }
  return ans;
}

long long f(long long n, long long m) {
  if (m == 1) return 0;
  if (n <= 1) return n % m;
  vector<long long> fac = factorize(m);
  vector<long long> ans(fac.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    long long ex = f(n - 1, totient(fac[i]));
    ans[i] = mod_pow(n, ex, fac[i]);
  }
  return crt(ans, fac);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int pn = 0;
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[pn++] = i;
      for (int j = i + i; j < MN; j += i) {
        sieve[j] = true;
      }
    }
  }

  long long n, m;
  while (cin >> n >> m) {
    cout << f(n, m) << endl;
  }
  return 0;
}
