#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n;

  while (cin >> n) {
    vector<int> all(n);
    for (auto &i : all) cin >> i;

    if (n == 1) {
      cout << 1 << endl;
    } else {
      int ans = n - 2;
      int delta = all[n - 1] - all[n - 2];
      while (ans >= 0 && (all[ans + 1] - all[ans]) == delta) {
        ans--;
      }
      cout << ans + 2 << endl;
    }
  }
  return 0;
}
