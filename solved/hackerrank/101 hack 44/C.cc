#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void ext_euclid(long long a, long long b,
    long long &x, long long &y, long long &g) {
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

const long long mod = 1e9 + 7;

long long mult(long long x, long long y) {
  long long ans = x * y;
  if (ans >= mod)
    return ans % mod;
  return ans;
}

long long add(long long x, long long y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<long long> dp(n + 1);
  vector<long long> fact(n + 1);

  dp[1] = 0;
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fact[i] = mult(fact[i - 1], i);
    dp[i] = mult(dp[i - 1], dp[i - 1]);
    dp[i] = add(dp[i], mult(add(dp[i - 1], mod - 1), add(i, mod - dp[i -1])));
  }

  debug(dp[n]);
  debug(fact[n]);
  debug(mult(dp[n], fact[n - 1]));
  cout << mult(dp[n], fact[n]) << endl;
  return 0;
}
