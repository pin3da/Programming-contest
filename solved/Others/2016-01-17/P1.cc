#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long inf = 1LL << 60;
const int MN = 255;

long long ps[MN];

long long pref(int i, int j) {
  if (j < i) return 0;
  long long ans = ps[j];
  if (i)
    ans -= ps[i - 1];
  return ans;
}

long long dp[MN][MN];

long long go(vector<int> &a, int i, int j) {
  if (j <= i) return 0;

  if (dp[i][j] != -1) return dp[i][j];
  long long cost = inf;
  for (int k = i; k <= j; ++k) {
    cost = min(cost, go(a, i, k - 1) + go(a, k + 1, j) + pref(i, k - 1) + pref(k + 1, j));
  }
  return dp[i][j] = cost;
}

void solve(int n) {
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  ps[0] = a[0];
  for (int i = 1; i < a.size(); ++i)
    ps[i] = ps[i - 1] + a[i];

  memset(dp, -1, sizeof dp);
  cout << go(a, 0, a.size() - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n)
    solve(n);
  return 0;
}
