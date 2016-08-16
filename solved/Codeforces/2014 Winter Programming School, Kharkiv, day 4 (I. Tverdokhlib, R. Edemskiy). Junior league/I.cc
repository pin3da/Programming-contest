#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    long long a, b;
    cin >> a >> b;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
      cin >> arr[i];

    vector<long long> dp(n);
    dp[0] = arr[0] * a;
    long long best = - (1LL << 60);
    for (int i = 1; i < n; ++i) {
      dp[i] = max(dp[i - 1] + a * arr[i], arr[i] * a);
      best = max(best, dp[i]);
    }
    cout << best + b << endl;
  }

  return 0;
}
