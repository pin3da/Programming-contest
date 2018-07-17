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
  long long d; cin >> d;
  vector<long long> a(n);
  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());

  int ans = 2;
  for (int i = 1; i < n; i++) {
    long long t = a[i] - a[i - 1];
    if (t > 2 * d) {
      ans += 2;
    } else if (t == 2 * d) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
