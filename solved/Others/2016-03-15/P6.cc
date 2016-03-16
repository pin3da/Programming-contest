#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long inf = 1LL << 60;


long long dp[111][11];

long long go(vector<int> &a, int i, int k) {
  if (i >= a.size())
    return 0;

  if (dp[i][k] != -1)
    return dp[i][k];

  long long best = inf;
  if (k > 0) {
    long long cur = 0;
    for (int j = i; j < a.size(); ++j) {
      cur += a[j];
      long long xx = go(a, j + 1, k - 1);
      long long t = max(cur, xx);
      best = min(best, t);
    }
  } else {
    best = 0;
    for (int j = i; j < a.size(); ++j)
      best += a[j];
  }

  return dp[i][k] = best;
}

void solve() {
  int n, k, f;
  cin >> n >> k >> f;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  long long best = inf;
  long long heaviest;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < k; ++i) {
    long long cur = go(a, 0, i);
    if (cur * f * k < best) {
      best = cur * f * k;
      heaviest = cur;
    }
  }
  cout << heaviest << " $" << best << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
