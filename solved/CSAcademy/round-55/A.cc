#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m; cin >> n >> m;
  vector<int> room(m);
  for (auto &i : room) cin >> i;
  for (int i = 0; i < n; i++) {
    int ans = 0;
    int lo, hi; cin >> lo >> hi;
    for (auto t : room) {
      if (t >= lo && t <= hi) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
