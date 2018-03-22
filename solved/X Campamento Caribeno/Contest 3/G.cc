#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MAXN = 333 * 2;
const long long mod = 998244353;

long long fact[MAXN];
long long fact_inv[MAXN];

long long comb(int n, int m) {
  long long ans = (fact[n] * fact_inv[m]) % mod;
  return (ans * fact_inv[n - m]) % mod;
}

long long mod_pow(long long b, long long e) {
  long long a = 1;
  while (e > 0) {
    if (e & 1) a = (a * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return a;
}

long long mod_inv(long long b) {
  return mod_pow(b, mod - 2);
}

long long G(int n) {
  if (n == 0) return 1;
  return mod_pow(2, comb(n, 2));
}

long long C[MAXN];

void solve() {
  int t;
  while (cin >> t) cout << C[t] << endl;
}

void pre() {
  fact[0] = 1;
  for (long long i = 1; i < MAXN; i++)
    fact[i] = (fact[i - 1] * i) % mod;

  for (long long i = 0; i < MAXN; i++)
    fact_inv[i] = mod_inv(fact[i]);


  C[1] = 1;

  for (int n = 2; n < MAXN; n++) {
    long long acc = 0;
    for (int k = 0; k <= n - 2; k++) {
      long long cur = (comb(n - 1, k) * C[k + 1]) % mod;
      cur = (cur * G(n - 1 - k)) % mod;
      acc = (acc + cur) % mod;
    }
    C[n] = (G(n) - acc + mod) % mod;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  pre();
  solve();
  return 0;
}

