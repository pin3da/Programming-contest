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
    int ans = -1;
    for (int n = 3; n <= 360; n++) {
      if ((360 % n) == 0) {
        if ((180 - 360 / n) == x) {
          ans = n;
          break;
        }
        if (((180 - (360 / n)) % (n - 2)) == 0) {
          int a = (180 - 360 / n) / (n - 2);
          if (((180 - 360 / n) >= x) && ((x % a) == 0)) {
            ans = n;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
