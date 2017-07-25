using namespace std;

#include <bits/stdc++.h>

const long long mod = 1e9 + 7;

const int MN = 2002;
long long dp[MN][MN];

long long go(int id, int prev, int n, int k) {
  if (id == k) return 1;
  long long ans = 0;
  if (dp[id][prev] != -1) return dp[id][prev];
  for (int i = 1; i * prev <= n; ++i) {
    ans = (ans + go(id + 1, i * prev, n, k)) % mod;
  }
  return dp[id][prev] = ans;
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    memset(dp, -1, sizeof dp);
    cout << go(0, 1, n, k) << endl;
  }
  return 0;
}
