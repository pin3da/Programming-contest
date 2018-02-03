#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif

void solve() {
  int n;
  cin >> n;

  int cur = 1;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;

    cur = max(cur, l);

    if (cur <= r) {
      ans[i] = cur++;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
