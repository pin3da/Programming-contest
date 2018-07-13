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
  vector<vector<int>> a(n, vector<int>(2));

  int last = 1e9;

  int ok = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    if (a[i][0] < a[i][1]) swap(a[i][0], a[i][1]);
    if (a[i][0] <= last) {
      last = a[i][0];
    } else {
      if (a[i][1] <= last) {
        last = a[i][1];
      } else {
        ok = false;
      }
    }
  }
  puts(ok ? "YES" : "NO");

  return 0;
}
