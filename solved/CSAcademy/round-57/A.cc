#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  string line;
  cin >> line;
  vector<int> t(26);
  for (auto &i : t) cin >> i;
  int ans = 0;
  for (auto &i : line) {
    ans += t[i - 'a'];
  }
  cout << ans << endl;
  return 0;
}
