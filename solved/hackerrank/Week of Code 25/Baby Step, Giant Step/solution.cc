#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl


int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int q; cin >> q;
  while (q--) {
    long long a, b, d;
    cin >> a >> b >> d;
    long long ans = d / b;
    long long pos = ans * b;
    if (d == pos)
      cout << ans << endl;
    else if ((d - pos) == a)
      cout << ans + 1 << endl;
    else {
      if (ans) {
        long long c = (ans - 1) * b;
        if (d - c < 2 * b) {
          cout << ans + 1 << endl;
          continue;
        }
      }
      cout << ans + 2 << endl;
    }
  }
  return 0;
}
