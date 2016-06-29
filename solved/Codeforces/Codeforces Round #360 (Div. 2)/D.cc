#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

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
  long long n, k;
  while (cin >> n >> k) {
    vector<long long> a(n);
    long long g = 0;
    for (auto &i : a) {
      cin >> i;
      g = __gcd(g, i);
    }

    long long num = 1;
    int ok = false;
    for (auto &i : a) {
      num *= i;
      if (num / g >= k) {
        ok = true;
        break;
      }
    }
    if (ok && __gcd(k, g) == 1) {
      long long g_inv = mod_inv(g, k);
      long long num = 1;
      for (auto &i : a)
        num = (num * i) % k;
      num = (num * g_inv) % k;
      if (num == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
