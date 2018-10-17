#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;

  int ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      ok = false;
    }
    if (i + 2 < n) {
      long long extra = b[i] - a[i];
      a[i] += extra;
      a[i + 1] += extra * 2;
      a[i + 2] += extra * 3;
    } else {
      if (a[i] != b[i])
        ok = false;
    }
  }

  puts(ok ? "TAK" : "NIE");
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
