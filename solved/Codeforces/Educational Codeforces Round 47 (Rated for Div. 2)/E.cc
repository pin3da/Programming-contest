#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  cin >> n;
  vector<long long> a(n), d(n);
  for (auto &i : a) cin >> i;

  long long x = 0;
  d[0] = a[0];
  for (int i = 1; i < n; i++) {
    x = (2 * x) % mod;
    x = (x + a[i - 1]) % mod;
    d[i] = (x + a[i]) % mod;
  }

  long long ans = 0, den = 1;
  for (int i = n - 1; i >= 0; i--) {
    ans = (ans + ((d[i] * den) % mod)) % mod;
    den = (2 * den) % mod;
  }

  cout << ans << '\n';
  return 0;
}
