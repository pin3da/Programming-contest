#include<bits/stdc++.h>
using namespace std;

int n, c;

const int MN = 2 * 100001;
int dp[MN][2];

int go(vector<int> &val) {

  dp[n][0] = dp[n][1] = 0;

  for (int i = n - 1; i >= 0; --i) {
    for (int t = 0; t < 2; ++t) {
      if (t)
        dp[i][t] = max(dp[i + 1][0] + val[i], dp[i + 1][1]);
      else
        dp[i][t] = max(dp[i + 1][1] - (val[i] + c), dp[i + 1][0]);
    }
  }

  return dp[0][0];
}

int main() {
  while (cin >> n >> c) {
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
      cin >> val[i];
    }
    cout << go(val) << endl;
  }
  return 0;
}
