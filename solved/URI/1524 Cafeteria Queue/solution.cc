#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long inf = 1LL << 60;

long long add(long long x, long long y) {
  return min(inf, x + y);
}

const int MN = 1001;
long long dp[MN][MN];

long long go(vector<long long> &a, int i, int k) {
  if (i >= a.size()) {
    if (k != 0)
      return inf;
    return 0;
  }
  if (dp[i][k] != -1)
    return dp[i][k];

  long long best = add(go(a, i + 1, k), ((i == 0) ? a[i] : a[i] - a[i - 1]));
  if (k > 0) {
    best = min(best, go(a, i + 1, k - 1));
  }
  return dp[i][k] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    vector<long long> a(n);
    for (int i = 1; i < n; ++i)
      cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(a, 0, k - 1) << endl;
  }
  return 0;
}

