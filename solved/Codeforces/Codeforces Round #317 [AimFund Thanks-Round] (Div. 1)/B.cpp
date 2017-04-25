// http://codeforces.com/contest/571/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int l_len, s_len;
const long long inf = 1LL << 60;
const int MN = 5010;
long long dp[MN][MN];

long long go(vector<int> &a, int l, int s) {
  if ((l + s) == 0) return 0;

  if (dp[l][s] != -1)
    return dp[l][s];
  long long best = inf;
  int id = l * l_len + s * s_len;
  if (l > 0) best = min(best, go(a, l - 1, s) + a[id - 1] - a[id - l_len]);
  if (s > 0) best = min(best, go(a, l, s - 1) + a[id - 1] - a[id - s_len]);
  return dp[l][s] = best;
}

void solve(int n, int k) {
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  l_len = n / k;
  s_len = l_len + 1;
  int s = n % k;
  int l = k - s;
  memset(dp, -1, sizeof dp);
  cout << go(a, l, s) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, k;
  while (cin >> n >> k)
    solve(n, k);
  return 0;
}
