#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int bits(int a) {
  return __builtin_popcount(a);
}

int leftbit(int c) {
  int ans = 0;
  while (c > 0) {
    ans++;
    c >>= 1;
  }
  return ans;
}

int dp[32][32][32][2];

int go(int idx, int ta, int tb, int carry, const int& c) {
  if (idx >= leftbit(c)) {
    return (carry == 0) && (ta == 0) && (tb == 0);
  }

  int& ans = dp[idx][ta][tb][carry];
  if (ans != -1) return ans;

  ans = 0;
  if ((c >> idx) & 1) {
    if (carry) {
      if (ta && tb) ans += go(idx + 1, ta - 1, tb - 1, 1, c); // 11
      ans += go(idx + 1, ta, tb, 0, c); // 01
    } else {
      if (ta) ans += go(idx + 1, ta - 1, tb, 0, c); // 01
      if (tb) ans += go(idx + 1, ta, tb - 1, 0, c); // 01
    }
  } else { // need = 0
    if (carry) {
      if (ta) ans += go(idx + 1, ta - 1, tb, 1, c); // 10
      if (tb) ans += go(idx + 1, ta, tb - 1, 1, c); // 10
    } else {
      ans += go(idx + 1, ta, tb, 0, c); // 00
      if (ta && tb) ans += go(idx + 1, ta - 1, tb - 1, 1, c); // 10
    }
  }
  return ans;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  memset(dp, -1, sizeof dp);
  cout << go(0, bits(a), bits(b), 0, c) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
