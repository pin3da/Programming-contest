#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int go(const string &line, char cur) {
  int ans = 0;
  size_t i = 0;
  while (i < line.size()) {
    if (line[i] == cur) {
      ans++;
      while (i < line.size() && line[i] == cur) i++;
    }
    i++;
  }
  return ans;
}

void solve() {
  string line;
  cin >> line;
  cout << min(go(line, 'U'), go(line, 'D')) << endl;
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
