using namespace std;
#include <bits/stdc++.h>

const long long mod = 1000000007;

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans = (ans + mod_pow(k, __gcd(i, n))) % mod;
  ans = (ans * mod_pow(n, mod - 2)) % mod;
  printf("%lld\n", ans);
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
