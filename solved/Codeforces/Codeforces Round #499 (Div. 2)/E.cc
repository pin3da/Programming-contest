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

  int n, k; cin >> n >> k;

  int g = 0;
  vector<int> p(k);
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if ((t % k) == 0) p[0] = true;
    else g = __gcd(g, t % k);
  }

  int t = g;
  for (int i = 1; i < 2 * k; i++) {
    p[t] = true;
    t = (t + g) % k;
  }

  cout << accumulate(p.begin(), p.end(), 0) << endl;
  for (int i = 0; i < k; i++) {
    if (p[i]) cout << i << " ";
  }
  cout << endl;

  return 0;
}
