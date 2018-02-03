#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif


void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(k);
  for (auto &i : a) cin >> i;
  int mmax = 0;
  for (int i = 1; i <= n; i++) {
    int best = n + 1;
    for (auto j : a) {
      best = min(best, abs(i - j) + 1);
    }
    mmax = max(mmax, best);
  }
  cout << mmax << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}
