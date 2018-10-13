#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (i + 1 < n) {
      int ans = 1;
      while (ans * 10 <= t) ans *= 10;
      cout << ans << " ";
    } else {
      cout << 1 << " ";
    }
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc; cin >> tc;
  for (int i = 0; i < tc; i++)
    solve();

  return 0;
}
