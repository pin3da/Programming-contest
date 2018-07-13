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

  map<pair<int, int>, int> ab, ac, bc;

  set<pair<int, int>> all;
  for (auto x : divs[a[0]]) {
    for (auto y : divs[a[1]]) {
      pair<int, int> k = {min(x, y), max(x, y)};
      all.insert(k);
      vector<int> &o = divs[a[2]];
      ab[k] = o.end() - lower_bound(o.begin(), o.end(), k.second);
    }
  }

  for (auto x : divs[a[0]]) {
    for (auto y : divs[a[2]]) {
      pair<int, int> k = {min(x, y), max(x, y)};
      all.insert(k);
      vector<int> &o = divs[a[1]];
      ac[k] = o.end() - lower_bound(o.begin(), o.end(), k.second);
    }
  }

  for (auto x : divs[a[1]]) {
    for (auto y : divs[a[2]]) {
      pair<int, int> k = {min(x, y), max(x, y)};
      all.insert(k);
      vector<int> &o = divs[a[0]];
      bc[k] = o.end() - lower_bound(o.begin(), o.end(), k.second);
    }
  }

  long long ans = 0;
  for (auto it : all) {
    long long ext = ab[it] + ac[it] + bc[it]
            - min(ab[it], ac[it]) - min(ab[it], bc[it]) - min(ac[it], bc[it])
            + min(ab[it], min(ac[it], bc[it]));
    ans += ext;
  }
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
