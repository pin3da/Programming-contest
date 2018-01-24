// WA! ):
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<vector<int>> b(n, vector<int>(n));
  for (auto &it : b) for (auto &i : it) cin >> i;

  vector<set<int>> can_swap(n);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (b[i][j] && b[j][i]) {
        can_swap[i].insert(j);
        can_swap[j].insert(i);
      }
    }
  }

  vector<int> id(n);
  for (int i = 0; i < n; i++)
    id[i] = i;

  int possible = true;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n && possible; i++) {
    int ok = b[i][i];
    if (!ok) {
      int fixed = false;
      for (int j = 0; j < n && !fixed; j++) {
        if (j < i) {
          if (can_swap[id[i]].count(id[j])) {
            swap(id[i], id[j]);
            swap(b[i], b[j]);
            ans.emplace_back(i, j);
            fixed = true;
          }
        } else if (j > i) {
          if (b[j][i]) {
            swap(id[i], id[j]);
            swap(b[i], b[j]);
            ans.emplace_back(i, j);
            fixed = true;
          }
        }
      }

      possible &= fixed;
    }
  }

  if (!possible) {
    cout << -1 << endl;
  } else {
    for (auto it : ans) {
      cout << "R " << it.first + 1 << " " << it.second + 1 << endl;
    }
  }
  return 0;
}
