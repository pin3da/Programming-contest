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

  int inv = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) inv++;
  }
  if (inv == 0) {
    puts("YES");
    return;
  }
  if (inv == 1) {
    if (a[0] >= a[n - 1]) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
