#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

long long inf = 10000;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--) {
    long long x;
    cin >> x;
    long long ans = inf;
    for (long long a = 1; a <= x; a++) {
      if ((x % a) != 0) continue;
      for (long long n = 3; n < ans; n++) {
        if (x * n > 180 * n - 360) continue;
        if ((a * n * (n - 2) + 360) == (180 * n)) {
          ans = min(ans, n);
        }
      }
    }
    if (ans == inf) {
      cout << 360 << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
