#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 100000007;

ll mod_pow(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

ll log(ll a, ll b) {
  ll m = ceil(sqrt(mod));

  map<ll,ll> table;
  for (ll j = 0, act = 1; j < m; j++, act = (act * a) % mod)
    table[act] = j;
  ll inv = mod_pow(a, mod - 2);
  inv = mod_pow(inv, m);

  ll c = b;
  for (int i = 0; i < m; i++)
    if (table.count(c))
      return i * m + table[c];
    else
      c = (c * inv) % mod;
}

int main() {
  int tc; scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    ll k, res;
    scanf("%lld %lld", &k, &res);
    printf("Case %d: %lld\n", i + 1, log(k, res));
  }
  return 0;
}
