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

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (n > m) {
    cout << "YES" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] > b[m - n + i]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
