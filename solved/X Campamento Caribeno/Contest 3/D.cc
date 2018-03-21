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

const int MN = 1e5 + 10;
const long long mod = 1e9 + 7;

long long fact[MN];

void pre() {
  fact[0] = 1;
  for (int i = 1; i < MN; i++)
    fact[i] = (fact[i - 1] * i) % mod;
}

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

long long mod_inv(long long x) {
  return mod_pow(x, mod - 2);
}

void solve() {
  long long n; cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= mod;
    if (i) a[i] = (a[i - 1] + a[i]) % mod;
  }

  long long den = 1;
  for (int i = 0; i < n; i++) {
    den = (den * (a[i] + i + 1) % mod) % mod;
  }

  cout << (fact[n] * mod_inv(den)) % mod << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  pre();
  solve();
  return 0;
}

