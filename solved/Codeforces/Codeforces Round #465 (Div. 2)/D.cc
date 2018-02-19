#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

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

long long mod_inv(long long x) {
  return mod_pow(x, mod - 2);
}

long long mult(long long x, long long y) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}

long long add(long long x, long long y) {
  return (x + y) % mod;
}

void solve() {
  long long n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  vector<long long> dp(n + 1);

  const long long minv = mod_inv(m);

  for (int i = n - 1; i >= 0; i--) {

    if ((a[i] != 0) && (b[i] != 0)) {
      if (a[i] == b[i]) {
        dp[i] = dp[i + 1];
      } else {
        dp[i] = a[i] > b[i];
      }
    } else {
      if (a[i] == 0 && b[i] == 0) {
        // dp[i] = (m - 1) / (2 * m) + 1/m * dp[i + 1]
        dp[i] = mult(m - 1, mod_inv((2 * m) % mod));
        dp[i] = add(dp[i], mult(dp[i + 1], minv));
      } else if (a[i] == 0) {
        long long extra = mult(m - b[i], minv);
        // dp[i] = fract(extra, m) + fract(1, m) * dp[i + 1];
        dp[i] = add(extra, mult(dp[i + 1], minv));
      } else if (b[i] == 0) {
        long long extra = mult(a[i] - 1, minv);
        // dp[i] = fract(extra, m) + fract(1, m) * dp[i + 1];
        dp[i] = add(extra, mult(dp[i + 1], minv));
      }
    }
  }
  cout << dp[0] % mod << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

