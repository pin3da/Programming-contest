using namespace std;
#include <bits/stdc++.h>

const int MN = 222;
long double dp[MN][MN];
long double dp2[MN][MN];

long double go(int n, int m) {
  if (n == 0)
    return  m;

  if (dp[n][m] > -0.5)
    return dp[n][m];

  long double ans = 0;
  if (n > 0) {
    ans += go(n - 1, m + 1) * (n / (long double)(n + m));
  }
  if (m > 0)
    ans += go(n, m - 1) * (m / (long double) (n + m));
  return dp[n][m] = ans;
}

long double go2(int n, int m) {
  if (n == 0)
    return  0;

  if (dp2[n][m] > -0.5)
    return dp2[n][m];

  long double ans = 0;
  if (n > 0)
    ans += (1 + go2(n - 1, m + 1)) * (n / (long double)(n + m));
  if (m > 0)
    ans += (1 + go2(n, m - 1)) * (m / (long double) (n + m));
  return dp2[n][m] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  for (int i = 0; i < MN; ++i)
   for (int j = 0; j < MN; ++j)
     dp[i][j] = dp2[i][j] = -1;


  while (cin >> n >> m && (n + m)) {
    cout << fixed << setprecision(12) << go(n, m) << " " << go2(n, m) << endl;
    // printf("%.12lf %.12lf\n", (double)go(n, m) + 1e-15, (double)go2(n, m) + 1e-15);
  }
  return 0;
}
