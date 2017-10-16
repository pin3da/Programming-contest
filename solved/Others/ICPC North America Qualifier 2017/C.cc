#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int inf = 3000000;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i: a) cin >> i;

  int target = a[n - 1] + a[n - 2];

  vector<int> dp(target + 1);
  vector<int> greedy(target + 1);

  for (int i = 1; i <= target; i++) {
    dp[i] = inf;
    for (int j = 0; j < n; j++) {
      if (a[j] <= i) {
        dp[i] = min(dp[i], dp[i - a[j]] + 1);
      }
    }

    for (int j = n - 1; j >= 0; j--) {
      if (a[j] <= i) {
        greedy[i] = greedy[i - a[j]] + 1;
        break;
      }
    }
  }
  int ok = true;
  for (int i = 0; ok && i <= target; i++) {
    if (dp[i] < greedy[i])
      ok = false;
  }
  puts(ok ? "canonical" : "non-canonical");
}
int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  solve();
  return 0;
}
