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

  int n, m;
  cin >> n >> m;
  if (m < n) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> a(200);
  for (int i = 0; i < m; i++) {
    int t; cin >> t;
    a[t]++;
  }

  int best = 0;
  for (int ans = 1; ans < 200; ans++) {
    int total = 0;
    for (auto it : a) {
      total += it / ans;
    }
    if (total >= n) best = ans;
  }

  cout << best << endl;
  return 0;
}
