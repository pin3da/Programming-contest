#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, b;
  cin >> n >> b;
  vector<int> data(n);
  for (auto &it : data) cin >> it;

  vector<vector<int>> frec(n, vector<int>(2));

  vector<pair<int, int>> cuts;

  for (int i = 0; i < n; i++) {
    frec[i][data[i]&1]++;
    if (i > 0) {
      frec[i][0] += frec[i - 1][0];
      frec[i][1] += frec[i - 1][1];
      cuts.emplace_back(abs(data[i] - data[i - 1]), i - 1);
    }
  }

  sort(cuts.begin(), cuts.end());

  int ans = 0;
  for (auto c : cuts) {
    if (frec[c.second][0] == frec[c.second][1]) {
      if (c.first <= b) {
        ans++;
        b -= c.first;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
