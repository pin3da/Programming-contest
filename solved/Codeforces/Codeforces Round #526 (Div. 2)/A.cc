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
  int n;
  cin >> n;
  vector<int> a(n);

  for (auto &it : a) cin >> it;

  long long best = 1LL << 60;
  for (int x = 0; x <= 100; x++) {
    long long cost = 0;

    for (int i = 0; i < n; i++) {
      cost += (a[i] * (abs(x - i) + i + x) * 2);
    }

    best = min(best, cost);
  }

  cout << best << endl;

  return 0;
}
