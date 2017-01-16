#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int q; cin >> q;
  long long x;
  while (q--) {
    cin >> x;
    long long ans = 0;
    int top = 0;
    for (int i = 0; i < 60; ++i)
      if ((x >> i) & 1) top = i;

    for (int i = 0; i < top; ++i) {
      if (!((x >> i) & 1)) {
        ans += (1LL << i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
