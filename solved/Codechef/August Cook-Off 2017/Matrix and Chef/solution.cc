#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void fix_row(vector<vector<int>> &d, vector<int> &ans) {
  int n = ans.size();

  if (d[1][2] == (d[0][1] + d[0][2])) {
    ans[1] = -d[0][1];
    ans[2] = d[0][2];
    if (ans[1] == 0) {
      ans[1] = d[0][1];
      ans[2] = -d[0][2];
    }
  } else if (d[1][2] == abs(d[0][1] - d[0][2])) {
    ans[1] = -d[0][1];
    ans[2] = -d[0][2];
  } else {
    assert(false);
  }

  int last = -1;
  for (int i = 1; i < 3; i++) {
    if (ans[i] != 0) last = i;
  }

  for (int i = 3; i < n; i++) {
    ans[i] = -d[0][i];
    if (last != -1 && (abs(ans[i] - ans[last]) != d[i][last])) {
      ans[i] = d[0][i];
    }
    if (ans[i] != 0) last = i;
  }

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;

#ifdef LOCAL
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(llabs(ans[i] - ans[j]) != d[i][j]) {
        debug(i); debug(j);
        cout << ans[i] << " " << ans[j] << endl;
        debug(d[i][j]);
        assert(false);
      }
    }
  }
#endif


}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> d(n, vector<int> (n));
  for (auto &i : d) for (auto &j : i) cin >> j;

  vector<int> ans(n);

  fix_row(d, ans);

  while (q--) {
    int p; cin >> p;
    p--;
    for (int i = 0; i < n; i++) {
      int t; cin >> t;
      d[i][p] = d[p][i] = t;
    }
    fix_row(d, ans);
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
