#include <bits/stdc++.h>
using namespace std;
const int MN = 110;

int n;
int v[MN], ps[MN];

int rsq(int a, int b) {
  return ps[b] - (a == 0 ? 0 : ps[a - 1]);
}

int dp[MN][MN];
int best(int i, int j) {
  if (dp[i][j] != -INT_MAX)
    return dp[i][j];

  if (i > j)
    return dp[i][j] = 0;

  int ans = -INT_MAX;
  for (int k = i; k <= j; k++)
    ans = max(ans, rsq(i, k) - best(k + 1, j));
  for (int k = j; k >= i; k--)
    ans = max(ans, rsq(k, j) - best(i, k - 1));

  return dp[i][j] = ans;
}

int main() {
  
  while (cin >> n and n) {
    for (int i = 0; i < n; i++)
      cin >> v[i];

    ps[0] = v[0];
    for (int i = 1; i < n; i++)
      ps[i] = ps[i - 1] + v[i];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	dp[i][j] = -INT_MAX;
    
    cout << best(0, n - 1) << endl;
  }
  
  return 0;
}
