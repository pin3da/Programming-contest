#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long mod = 1000 * 1000 * 1000 + 7;

long long get(vector<vector<int>> &s, int i, int j) {
  if (i < 0 || j < 0) return 0;
  return s[i][j];
}

long long fact[55 * 55];

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
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 55 * 55; ++i)
    fact[i] = (fact[i - 1] * i) % mod;

  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<vector<int>> sum(n, vector<int> (m));
  sum[0][0] = a[0][0] == '#';
  for (int i = 1; i < n; ++i) {
    if (a[i][0] == '#')
      sum[i][0] = 1;
    sum[i][0] += sum[i - 1][0];
  }
  for (int i = 1; i < m; ++i) {
    if (a[0][i] == '#')
      sum[0][i] = 1;
    sum[0][i] += sum[0][i - 1];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i][j] == '#') sum[i][j] = 1;
      sum[i][j] += sum[i][j - 1] + sum[i - 1][j];
      sum[i][j] -= sum[i - 1][j - 1];
    }
  }

  int x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    x1--;y1--;x2--;y2--;
    x1--;y1--;
    long long total = (x2 - x1) * (y2 - y1);
    long long used = get(sum, x2, y2) - get(sum, x1, y2) - get(sum, x2, y1) + get(sum, x1, y1);
    if (used == 0) {
      cout << 0 << endl;
      continue;
    }
    long long den = (fact[used] * fact[total - used]) % mod;
    long long ans = (fact[total] * mod_inv(den, mod)) % mod;
    ans--;
    if (ans < 0) ans += mod;
    cout << ans << endl;
  }
  return 0;
}
