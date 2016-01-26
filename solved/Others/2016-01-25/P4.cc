#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 10001;
long long dp[MN][3][3];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &i : a)
      cin >> i;

    int t = 0;
    for (int i = 0; i + 1 < n; ++i)
      dp[i][t][0] = dp[i][t ^ 1][1] = max(a[i], a[i + 1]);

    for (int len = 2; len < n; ++len) {
      for (int k = 0; k < 2; ++k) {
        for (int i = 0; i + len < n; ++i) {
          int j = i + len;
          dp[i][t][k] = max(a[i] * k + dp[i + 1][t ^ 1][k ^ 1],
                              a[j] * k + dp[i][t ^ 1][k ^ 1]);
        }
      }
      t ^= 1;
    }

    cout << dp[0][t ^ 1][1] << endl;
  }
  return 0;
}
