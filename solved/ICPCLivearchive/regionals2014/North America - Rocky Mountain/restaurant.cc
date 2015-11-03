using namespace std;
#include <bits/stdc++.h>

int base[20];


long long dp[20][33];
long long dp2[20][2][33];

long long go(int i, int sum, const int &n) {
  if (i == n)
    return 1;

  if (sum == 0)
    return 1;

  if (dp[i][sum] != -1)
    return dp[i][sum];

  long long ans = 0;
  for (int j = 0; j <= sum; ++j) {
    ans += go(i + 1, sum - j, n);
  }

  return dp[i][sum] = ans;
}

long long go2(int i, int top, int sum, const int &n) {
  if (i == n)
    return sum == 0;

  if (dp2[i][top][sum] != -1)
    return dp2[i][top][sum];

  int mmax = (top ? base[i]: sum);
  long long ans = 0;
  for (int j = 0; j <= mmax; ++j) {
    ans += go2(i + 1, (j == mmax) && top, sum - j, n);
  }
  return dp2[i][top][sum] = ans;
}

void solve(int n) {
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    cin >> base[i];
    tot += base[i];
  }

  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  cout << go(0, tot - 1, n) + go2(0, 1, tot, n)  << endl;
}

int main() {
  int n;
  while (cin >> n && n) {
    solve(n);
  }
  return 0;
}
