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

  map<long long, int> all;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    all[t]++;
  }

  int ans = 0;
  for (auto it : all) {
    int ok = false;
    for (int i = 0; i < 35; i++) {
       long long extra = (1LL << i) - it.first;
       if (extra > 0 && all.count(extra) && ((extra != it.first) || all[extra] > 1)) ok = true;
    }
    if (!ok) ans += it.second;
  }

  cout << ans << endl;

  return 0;
}
