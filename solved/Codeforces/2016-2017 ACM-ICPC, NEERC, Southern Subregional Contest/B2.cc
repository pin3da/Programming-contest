#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool query(int b, int e) {
  cout << "? " << b << ' ' << e << endl;
  string ans; cin >> ans;
  return ans == "<";
}


void solve() {
  int n; cin >> n;
  pair<int, int> ans(1, 1);
  int i = 0;
  if ((n & 1) == 0) {
    if (query(1, 2)) {
      ans.first = 1;
      ans.second = 2;
    } else {
      ans.first = 2;
      ans.second = 1;
    }
    i = 3;
  } else {
    i = 2;
  }

  for (; i + 1 <= n; i += 2) {
    if (query(i, i + 1)) {
      if (query(i, ans.first))
        ans.first = i;
      if (query(ans.second, i + 1))
        ans.second = i + 1;
    } else {
      if (query(i + 1, ans.first))
        ans.first = i + 1;
      if (query(ans.second, i))
        ans.second = i;
    }
  }

  cout << "! " << ans.first << ' ' << ans.second << endl;
}

int main() {
  int t; cin >> t;

  for (int i = 0; i < t; ++i)
    solve();

  return 0;
}
