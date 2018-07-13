#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int MN = 100001;
vector<int> divs[MN];

void solve() {

  vector<int> a(3);
  for (auto &it : a) cin >> it;

  vector<int> id(3);
  iota(id.begin(), id.end(), 0);

  map<pair<int, int>, set<int>> all;
  long long ans = 0;
  do {
    for (auto it : divs[a[id[0]]]) {
      for (auto it2 : divs[a[id[1]]]) {
        int x = min(it, it2), y = max(it, it2);
        all[{x, y}].insert(lower_bound(divs[a[id[2]]].begin(), divs[a[id[2]]].end(), y), divs[a[id[2]]].end());
        // ans += lower_bound(divs[a[id[2]]].begin(), divs[a[id[2]]].end(), y) - divs[a[id[2]]].end();
      }
    }
  } while (next_permutation(id.begin(), id.end()));

  for (auto it : all)
    ans += it.second.size();
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  for (int i = 1; i < MN; i++) {
    for (int j = i; j < MN; j += i) {
      divs[j].emplace_back(i);
    }
  }

  int t; cin >> t;
  while (t--) solve();
  return 0;
}
