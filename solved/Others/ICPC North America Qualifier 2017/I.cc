#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if ((a[i] - 1) != a[i - 1]) {
      ans = i + 1;
      break;
    }
  }
  assert(ans > 0);
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
