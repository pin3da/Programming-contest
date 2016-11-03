#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n; scanf("%d", &n);
  int win = 0;
  for (int i = 0; i < n; ++i) {
    int b, x;
    scanf("%d%d", &b, &x);
    int cur = 0;
    if (b == 1) {
      cur ^= x & 1;
    } else {
      while (x > 0) {
        cur ^= (x & 1);
        x /= b;
      }
    }
    win ^= cur;
  }
  puts(win ? "1" : "2");
}

int main() {
#ifndef LOCAL
  freopen("powers.in", "r", stdin);
#endif

  int t; scanf("%d", &t);
  while(t--) solve();

  return 0;
}
