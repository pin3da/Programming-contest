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

const int MAXL = 3 * (50 * 50 + 100);

const long long mod = 1e9 + 7;

long long fact[MAXL];
long long fact_inv[MAXL];

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

long long mod_inv(long long b) {
  return mod_pow(b, mod - 2);
}

long long comb(int n, int m) {
  long long ans = (fact[n] * fact_inv[m]) % mod;
  return (ans * fact_inv[n - m]) % mod;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  read(a);

  int len = accumulate(a.begin(), a.end(), 0LL) + 1;

  deque<long long> d(len);
  d[1] = 1;
  for (int i = 2; i < len; i++) {
    d[i] = 1;
    for (auto it : a) {
      d[i] = (d[i] * comb(it + i - 1, i - 1)) % mod;
    }
  }

  long long total = 0;
  while (len) {
    long long ans = d[len - 1];
    int i = len - 1;
    for (int j = 1; j <= i; j++) {
      long long sig = (j & 1) ? mod-1 : 1;
      long long f = (sig * comb(i, j)) % mod;
      f = (f * d[i - j]) % mod;
      ans = (ans + f) % mod;
    }
    total = (total + ans) % mod;
    len--;
  }

  cout << total << endl;
}

void pre() {
  fact[0] = fact_inv[0] = 1;
  for (int i = 1; i < MAXL; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    fact_inv[i] = mod_inv(fact[i]);
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

