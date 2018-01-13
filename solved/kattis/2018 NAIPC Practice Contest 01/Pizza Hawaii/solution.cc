#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  map<string, long long> inv_fore, inv;
  for (int i = 0; i < n; i++) {
    string name; cin >> name;
    int w;
    cin >> w;
    for (int j = 0; j < w; j++) {
      string ing; cin >> ing;
      inv_fore[ing] |= 1LL << i;
    }
    cin >> w;
    for (int j = 0; j < w; j++) {
      string ing; cin >> ing;
      inv[ing] |= 1LL << i;
    }
  }

  map<long long, vector<string>> fore, eng;
  for (auto i : inv_fore)
    fore[i.second].push_back(i.first);

  for (auto i : inv)
    eng[i.second].push_back(i.first);

  vector<pair<string, string>> ans;

  for (auto &it : fore) {
    long long mask = it.first;
    for (auto &w1 : it.second) {
      for (auto &w2 : eng[mask]) {
        ans.emplace_back(w1, w2);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (auto &it : ans) {
    cout << "(" << it.first << ", " << it.second << ")" << endl;
  }
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    if (i) cout << endl;
    solve();
  }
  return 0;
}
