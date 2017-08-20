#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  string s, t;
  cin >> s >> t;
  if (s[0] == t[0]) {
    cout << "B" << endl;
  } else {
    if (s.size() > 1) {
      cout << "A" << endl;
    } else {
      cout << "B" << endl;
    }
  }
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
