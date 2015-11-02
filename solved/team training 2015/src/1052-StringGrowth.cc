#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

class mat {
public:
  ll a, b, c, d;

  mat() {}
  mat(int x, int y, int z, int w) : a(x), b(y), c(z), d(w) {}

  mat operator*(mat m) {
    return mat((a*m.a + b*m.c) % mod, (a*m.b + b*m.d) % mod,
	       (c*m.a + d*m.c) % mod, (c*m.b + d*m.d) % mod);
  }
};

mat pow(mat a, ll n) {
  mat ans(1, 0,
	  0, 1);
  while (n > 0) {
    if (n & 1)
      ans = ans * a;
    a = a * a;
    n >>= 1;
  }
  return ans;
}

ll mod_pow(ll a, ll n) {
  ll ans = 1;
  while (n > 0) {
    if (n & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ans % mod;
}

void solve() {
  ll n, x;
  ll m, y;
  ll k;
  scanf("%lld %lld %lld %lld %lld", &n, &x, &m, &y, &k);

  mat N = pow(mat(1, 1, 1, 0), n);
  mat M = pow(mat(1, 1, 1, 0), m);

  ll den = N.c * M.d - M.c * N.d;
  if (den == 0) {
    printf("Impossible\n");
  } else {
    ll s1 = (x * M.d - y * N.d) / den; // (x * M.d - y * N.d) % mod * mod_pow(den, mod - 2);
    ll s0 = (y * N.c - x * M.c) / den; // (y * N.c - x * M.c) % mod * mod_pow(den, mod - 2);

    if (s0 < 0 or s1 < 0 or s1 < s0) { // No positive length starting string
      printf("Impossible\n");
    } else if ((x * M.d - y * N.d) % den != 0 or (y * N.c - x * M.c) % den != 0) { // No integer length starting string
      printf("Impossible\n");
    } else {
      mat K = pow(mat(1, 1, 1, 0), k);
      ll sk = (K.c * s1 + K.d * s0) % mod;
      printf("%lld\n", sk);
    }
  }
}

int main() {
  int tc; scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
