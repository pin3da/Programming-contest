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

  int n;
  cin >> n;
  vector<int> cap(n), cool(n);
  vector<pair<int, int>> withCap, ans;

  for (int i = 0; i < n; i++) {
    cin >> cap[i];
    withCap.emplace_back(cap[i], i);
  }

  sort(withCap.begin() + 1 , withCap.end());
  reverse(withCap.begin() + 1 , withCap.end());

  cool[0] = 1;
  int last = 1;
  for (int i = 0; i < n; i++) {
    while (cool[i] && last < n && (withCap[i].first-- > 0)) {
      ans.emplace_back(withCap[i].second + 1, withCap[last].second + 1);
      cool[last++] = 1;
    }
  }
  if (last != n)
    cout << -1 << endl;
  else {
    cout << ans.size() << endl;
    for (auto it : ans)
      cout << it.first << " " << it.second << endl;
  }

  return 0;
}
