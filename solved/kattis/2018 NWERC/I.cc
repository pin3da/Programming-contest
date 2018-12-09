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
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  sort(a.begin(), a.end());
  double ans = 1e100;
  int ok = true;
  for (int i = 1; i <= n; i++) {
    if (a[i-1] > i) ok = false;
    double cur = double(a[i-1]) / double(i);
    ans = min(ans, cur);
  }

  if (ok) {
    cout << fixed << setprecision(8) << ans << endl;
  } else {
    cout << "impossible" << endl;
  }


  return 0;
}
