#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    unordered_map<int, int> a;
    a.reserve(2 * n);
    vector<pair<int, int>> all;
    int x, y;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      all.emplace_back(min(x, y), max(x, y));
      a[x]++;
      a[y]++;
    }

    unordered_map<int, int> rem;
    rem.reserve(2 * n);
    int need = 0;
    for (int i = 0; i < n; ++i) {
      int f = all[i].first, s = all[i].second;
      if (a[f] == 1 || a[s] == 1) continue;
      rem[f]++;
      rem[s]++;
      need++;
    }

    int k = 0;
    for (auto &i : rem) {
      if (i.second >= 3) k++;
    }

    if (a.size() >= n && rem.size() >= need && k < 2) {
      cout << "possible" << endl;
    } else
      cout << "impossible" << endl;
  }

  return 0;
}
