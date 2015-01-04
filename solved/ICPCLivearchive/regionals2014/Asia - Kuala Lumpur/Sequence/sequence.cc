using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

const int mod = 1000000007;

int dp[1111][1111];
long long go(int k, int ones, const int &n) {
  int zeroes =  n - ones;

  // cout << k << " " << ones << " " << zeroes << endl;
  if (k == 0)
    if (ones)
      return 0;
    else
      return 1;

  if (dp[k][ones] != -1)
    return dp[k][ones];

  long long ans = 0;
  if (ones)
    ans = (ans + ones * go(k - 1, ones - 1, n) ) % mod;
  if (zeroes)
    ans = (ans + zeroes * go(k - 1, ones + 1, n) ) % mod;

  return dp[k][ones] = ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  int ones = 0;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t) ones++;
  }

  memset(dp, -1, sizeof dp);
  cout << go(k, ones, n) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
