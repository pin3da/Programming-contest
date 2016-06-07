#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> d(n), dk(n);
    for (int i = 0; i < n; ++i) {
      cin >> d[i] >> dk[i];
    }

    int top = *max_element(dk.begin(), dk.end());
    int ans = 0;
    while (m--) {
      vector<vector<int>> cur(top + 1);
      for (int i = 2; i <= top; ++i) {
        for (int j = 0; j < n; ++j) {
          if (d[j] && ((i % d[j]) == 0) && i <= dk[j]) {
            cur[i].emplace_back(j);
          }
        }
      }
      int best = 0, id_best = -1;
      for (int i = 0; i < cur.size(); ++i) {
        if (cur[i].size() > best) {
          best = cur[i].size();
          id_best = i;
        }
      }
      if (id_best == -1) break;
      ans += best;
      for (auto &i : cur[id_best]) {
        d[i] = dk[i] = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
