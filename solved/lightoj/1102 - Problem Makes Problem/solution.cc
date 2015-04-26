using namespace std;
#include <bits/stdc++.h>

const long long mod = 1000000007ll;
const int mn = 2000002;
long long fact[mn];

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

void solve() {
  long long n, k;
  cin >> n >> k;
  long long num = fact[n + k - 1];
  long long den = (fact[n] * fact[k - 1]) % mod;
  printf("%lld\n", (num * mod_pow(den, mod - 2, mod)) % mod);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < mn; ++i) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
