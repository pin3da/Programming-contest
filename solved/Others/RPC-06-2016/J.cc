#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

int main() {
  int n;
  cout << fixed << setprecision(5);
  while (cin >> n) {
    vector<double> p(n);
    for (auto &i : p) {
      cin >> i;
      i /= 100.0;
    }
    sort(p.rbegin(), p.rend());
    vector<double> s;
    double best = 0;

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));

    dp[0][0] = 1.0;
    dp[0][1] = p[0];

    for (int i = 1; i < n; ++i) {
      dp[i][0] = 1.0;
      for (int j = 1; j <= i + 1; ++j) {
        dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1.0 - p[i]);
      }
    }

    for (int i = 1; i <= p.size(); i++) {
      int id = min<int>(p.size() - 1, i * 2 - 2);
      if (id & 1) id--;
      best = max(best, dp[id][i]);
    }
    cout << best << endl;
  }
  return 0;
}
