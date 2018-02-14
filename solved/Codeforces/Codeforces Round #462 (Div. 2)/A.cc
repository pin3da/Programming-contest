#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const long long inf = 3e18;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;

  long long best = inf;
  for (int i = 0; i < n; i++) {
    long long cur = -inf;
    for (auto j : b) {
      for (int k = 0; k < n; k++) {
        if (k != i)
          cur = max(cur, a[k] * j);
      }
    }
    best = min(best, cur);
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
//   int tc; cin >> tc;
//  while (tc--)
    solve();
  return 0;
}

