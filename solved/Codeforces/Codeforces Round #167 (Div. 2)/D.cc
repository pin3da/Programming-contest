#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


long long comp(long long n, long long &sub, long long mod) {
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    long long j = i;
    while (sub > 0 && ((j & 1) == 0)) {
      sub--;
      j /= 2;
    }
    ans = (ans * j) % mod;
  }
  return ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n; cin >> n;
  vector<int> a(n), b(n);
  long long total = 0;
  map<int, int> frec, first, second;
  for (int i = 0; i < 2 * n; i++) {
    int t;
    cin >> t;
    frec[t]++;
    if (i < n) a[i] = t;
    else b[i - n] = t;
  }

  long long mod; cin >> mod;

  for (int i = 0; i < n; i++) {
    total += a[i] == b[i];
  }

  long long ans = 1;
  for (auto it : frec) {
    long long times = comp(it.second, total, mod);
    ans = (ans * times) % mod;
  }
  cout << ans << endl;
  return 0;
}
