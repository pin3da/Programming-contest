#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1e9;

const int MN = 10001;
long long dp[MN];

long long go(vector<int> &t, int b) {
  if (b == -1) return 0;

  if (dp[b] != -1) return dp[b];
  long long best = inf;
  for (int k = 1; b - k >= -1; k++) {
    long long cost = max(t[b] - t[b - k + 1] - 1800 + 20, 20 * k) + 120;
    best = min(best, go(t, b - k) + cost);
  }
  return dp[b] = best;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  memset(dp, -1, sizeof dp);
  cout << go(a, n - 1) << endl;

  return 0;
}
