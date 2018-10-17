#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int solve() {
  int k, n;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.rbegin(), a.rend());
  int pos = 1;

  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      pos = i + 1;
      if (pos >= (k + 1)) return i;
    }
  }

  return n;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
