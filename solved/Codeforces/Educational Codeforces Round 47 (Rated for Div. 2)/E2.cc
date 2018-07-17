#include <bits/stdc++.h>

using namespace std;

template<class T, T mod>
struct mint_t {
  T val;
  mint_t() : val(0) {}
  mint_t(T v) : val(v % mod) {}

  mint_t operator + (const mint_t& o) const {
    return (val + o.val) % mod;
  }
  mint_t operator - (const mint_t& o) const {
    return (val - o.val) % mod;
  }
  mint_t operator * (const mint_t& o) const {
    return (val * o.val) % mod;
  }
};

typedef mint_t<long long, 998244353> mint;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  cin >> n;
  vector<long long> a(n);
  vector<mint> d(n);
  for (auto &i : a) cin >> i;

  mint x(0);
  d[0] = a[0];
  for (int i = 1; i < n; i++) {
    x = (x * 2);
    x = (x + a[i - 1]);
    d[i] = (x + a[i]);
  }

  mint ans(0), den(1);
  for (int i = n - 1; i >= 0; i--) {
    ans = (ans + (d[i] * den));
    den = (den * 2);
  }

  cout << ans.val << '\n';
  return 0;
}
