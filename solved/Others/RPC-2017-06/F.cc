#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  unordered_map<string, int> id;
  vector<string> inv(n);
  vector<int> solved(m);
  for (int i = 0; i < n; ++i) {
    string name; cin >> name;
    id[name] = i;
    inv[i] = name;
  }
  vector<set<pair<int, int>>> pref(m);
  for (int i = 0; i < m; ++i) {
    int len; cin >> len;
    for (int j = 0; j < len; ++j) {
      int t; string name;
      cin >> t >> name;
      pref[i].insert({t, id[name]});
    }
  }

  set<int> ans;
  while (true) {
    int seen = false;
    for (int i = 0; i < m; ++i) {
      if (solved[i]) continue;
      if (pref[i].size() == 0) {
        cout << "Impossible" << endl;
        return;
      }
      if ((pref[i].size() == 1) && (pref[i].begin()-> first == 1)) {
        seen = true;
        solved[i] = true;
        ans.insert(pref[i].begin()-> second);
        for (int j = 0; j < m; ++j) {
          if (!solved[j]) {
            pref[j].erase({2, pref[i].begin()-> second});
          }
        }
        break;
      }
    }
    if (!seen) break;
  }

  cout << ans.size() << endl;
  vector<string> tmp;
  for (auto i : ans)
    tmp.push_back(inv[i]);
  sort(tmp.begin(), tmp.end());
  for (auto i : tmp)
    cout << i << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--)
    solve();
}
