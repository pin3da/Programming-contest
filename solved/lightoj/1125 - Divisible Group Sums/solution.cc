using namespace std;
#include <bits/stdc++.h>

const int MN = 201,
          MD = 21,
          MM = 11;

long long dp[MN][MM][MD];

int D;

int sum(int a, int b) {
  long long ans = a + b;
  ans %= D;
  if (ans < 0)
     ans += D;
  return ans;
}

long long go(const vector<int> &a, int i, int t, int acc) {
  if (i == a.size() || t == 0)
    return (t == 0) && (acc % D) == 0;

  if (dp[i][t][acc] != -1)
    return dp[i][t][acc];
  return dp[i][t][acc] = go(a, i + 1, t, acc) + go(a, i + 1, t - 1, sum(acc, a[i]));
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int m, d;
  while (q--) {
    cin >> d >> m;
    D = d;
    memset(dp, -1, sizeof dp);
    vector<int> b = a;
    for (int i = 0; i < a.size(); ++i) {
      b[i] %= d;
      if (b[i] < 0)
        b[i] += d;
    }
    printf("%lld\n", go(b, 0, m, 0));
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
