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

  long long n, k, t;
  cin >> n >> k >> t;

  if (t <= k) {
    cout << t << endl;
  } else {
    if (t <= n) {
      cout << k << endl;
    } else {
      cout << k - (t - n) << endl;
    }
  }
  return 0;
}
