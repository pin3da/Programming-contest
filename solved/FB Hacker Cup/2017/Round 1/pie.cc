#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 321;

long long c[MN][MN];
const long long inf = 1LL << 60;

int N, M;

long long dp[MN][MN];

long long go(int day, int have) {
  if (day == (N + 1)) return 0;

  if (have >= N) return 0;

  if (dp[day][have] != -1)
    return dp[day][have];

  long long best = inf;
  for (int i = 0; i <= M; ++i) {
    long long op = i * i + c[day - 1][i] + go(day + 1, have + i);
    if ((have + i) >= day) {
      best = min(best, op);
    }
  }
  return dp[day][have] = best;
}

void solve() {
  int n, m;
  cin >> n >> m;
  N = n; M = m;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> c[i][j + 1];

    sort(c[i], c[i] + m + 1);

    for (int j = 0; j < m; ++j)
      c[i][j + 1] += c[i][j];

  }
  cout << go(1, 0) << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
