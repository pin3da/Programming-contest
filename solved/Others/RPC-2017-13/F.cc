#include<bits/stdc++.h>

using namespace std;
#define endl '\n'

const int MX = 5005;
int dp[MX][MX];
short arr[MX];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i <= n + 2; i++)
      for (int j = 0; j <= n + 2; j++) dp[i][j] = 0;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = n; j > i; j--) {
        int toadd = arr[i - 1] == arr[j - 1];
        dp[i][j] = dp[i - 1][j + 1] + toadd;
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
