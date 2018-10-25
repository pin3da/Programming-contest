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
  long long t;
  cin >> n >> t;
  vector<pair<long long, int>> a(n);
  vector<long long> b(n);
  for (auto &it : b) cin >> it;

  long long ans = 0;

  while (true) {
    long long sum = accumulate(b.begin(), b.end(), 0LL);
    if (sum == 0) break;
    int len = 0;
    for (auto it : b) if (it) len++;
    if (len == 0) break;

    ans += (t / sum) * len;
    t %= sum;

    for (auto &it : b) {
      if (it == 0) continue;
      if (it > t) it = 0;
      else {
        t -= it;
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
