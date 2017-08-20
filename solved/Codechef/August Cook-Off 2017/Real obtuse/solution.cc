#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  long long k, a, b;
  cin >> k >> a >> b;
  int da = llabs(a - b);
  int db = k - da;
  if (da == db) {
    cout << 0 << endl;
    return;
  }
  cout << min(da, db) - 1 << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
