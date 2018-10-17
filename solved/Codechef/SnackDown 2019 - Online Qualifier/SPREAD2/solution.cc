#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  long long ans = 0, cap = a[0], last  = 0;

  while (last < (n - 1)) {
    long long new_cap = cap;
    for (int i = 0; i < cap && last < (n - 1); i++) {
      last++;
      new_cap += a[last];
    }
    ans++;
    cap = new_cap;
  }

  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
