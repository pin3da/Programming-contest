#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, u, l;
  while (cin >> n >> l >> u) {
    long long ans = 0;
    for (int i = 31; i >= 0; --i) {
      if ((n >> i) & 1LL) {
        if (ans + (1LL << i) - 1 < l)
          ans += (1LL << i);
      } else {
        if (ans + (1LL << i) <= u)
          ans += (1LL << i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
