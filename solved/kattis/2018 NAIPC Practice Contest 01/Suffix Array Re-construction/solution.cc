#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl


void solve() {
  int len, n;
  cin >> len >> n;
  deque<int> ans(len, 0);
  int ok = true;

  for (int i = 0; i < n; i++) {
    int pos; cin >> pos;
    string line; cin >> line;
    for (int j = 0; j < (int)line.size() && j + pos - 1 < len && line[j] != '*'; j++) {
      if (ans[j + pos - 1] == 0) {
        ans[j + pos - 1] = line[j];
      } else {
        if (line[j] != ans[j + pos - 1])
          ok = false;
      }
    }

    for (int j = 0; len - 1 - j >= 0 && j < (int)line.size() && line[line.size() - j - 1] != '*'; j++) {
      if (ans[len - 1 - j] == 0) {
        ans[len - 1 - j] = line[line.size() - j - 1];
      } else {
        if (ans[len - 1 - j] != line[line.size() - j - 1])
          ok = false;
      }
    }
  }

  for (int i = 0; i < len; i++) {
    if (ans[i] == 0) ok = false;
  }

  if (ok) {
    for (int i = 0; i < len; i++) {
      cout << char(ans[i]);
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
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
