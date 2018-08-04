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

  int n, m, q;
  cin >> n >> m >> q;
  string text, pattern;
  cin >> text >> pattern;
  vector<int> match(n);
  for (int i = 0; i + m <= n; i++) {
    string t = text.substr(i, m);
    match[i] = (t == pattern);
  }

  for (int i = 1; i < n; i++) match[i] += match[i - 1];

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;r--;
    r = r - m + 1;
    if (l <= r) {
      int ans = match[r];
      if (l) ans -= match[l - 1];
      cout << ans << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}
