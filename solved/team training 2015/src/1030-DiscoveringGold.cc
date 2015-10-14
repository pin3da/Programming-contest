#include <bits/stdc++.h>
using namespace std;

const int MN = 110;
double dp[MN], gold[MN];
int n;

double f(int i) {
  if (dp[i] != -1)
    return dp[i];
  if (i >= n)
    return 0;
  
  double ans = 0;
  int maxs = min(6, n - i - 1);
  for (int s = 1; s <= maxs; s++) 
    ans += (gold[i + s] + f(i + s)) / maxs;;
  return dp[i] = ans;
}

double solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> gold[i];
  for (int i = 0; i < MN; i++)
    dp[i] = -1;

  double ans = gold[0];
  return ans + f(0);
}

int main() {
  int t; cin >> t;
  
  for (int i = 0; i < t; i++)
    cout << "Case " << i + 1 << ": " << fixed << setprecision(10) << solve() << endl;
  return 0;
}
