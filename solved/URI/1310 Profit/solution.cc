#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, c;
  while (cin >> n >> c) {
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      i -= c;
    }
    vector<int> dp(n);
    dp[0] = max(0, a[0]);
    for (int i = 1; i < n; ++i)
      dp[i] = max(dp[i - 1] + a[i], max(0, a[i]));
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }

  return 0;
}
