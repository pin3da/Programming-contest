#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  vector<long long> dp(222);

  dp[0] = 1;
  dp[2] = 1;
  dp[4] = 2;
  for (int i = 6; i < 222; i += 2) {
    for (int k = 1; k < i; k++) {
      dp[i] += dp[k - 1] * dp[i - k - 1];
    }
  }

  int n;
  while (cin >> n && n > 0) {
    cout << dp[n << 1] << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

