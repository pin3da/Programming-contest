#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n; cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  const long long mod = 10007;
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    ans += (a[i] * b[i]) % mod;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
