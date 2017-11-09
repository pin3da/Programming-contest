#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  deque<char> s(n);
  for (auto &i : s) cin >> i;
  map<char, char> m;
  m['L'] = 'R';
  m['R'] = 'L';
  m['D'] = 'U';
  m['U'] = 'D';

  int ans = 0;
  while (s.size()) {
    char cur = s.front(); s.pop_front();
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == m[cur]) {
        s.erase(s.begin() + i);
        ans += 2;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
