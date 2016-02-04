#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long mod = 1300031;

long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    exp >>= 1;
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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, c;
  vector<long long> f(5000000 + 10);
  f[0] = 1;
  for (int i = 1; i < f.size(); ++i)
    f[i] = (i * f[i - 1]) % mod;

  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> c;
    long long num = f[c + n - 1];
    long long den = mod_inv((f[c] * f[n - 1]) % mod, mod);
    cout << (num * den) % mod << endl;
  }

  return 0;
}
