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

  int n; cin >> n;

  multiset<int> a;
  int ans = 0;
  vector<int> all(n);
  for (int i = 0; i < n; i++) {
    cin >> all[i];
    a.insert(-all[i]);
  }

  sort(all.rbegin(), all.rend());

  for (auto it : all) {
    auto nxt = a.upper_bound(-it);
    if (nxt != a.end()) {
      ans++;
      a.erase(nxt);
    }
  }

  cout << ans << endl;
  return 0;
}
