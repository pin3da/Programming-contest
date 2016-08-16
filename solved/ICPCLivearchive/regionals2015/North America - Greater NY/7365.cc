#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;


const int MN = 33;
int dp[33];

long long go(vector<int> &valid, int n) {
  if (n == 0) return 1;

  if (dp[n] != -1) return dp[n];

  long long ans = 0;
  for (int i = 0; i < valid.size(); ++i) {
    if (valid[i] <= n)
      ans += go(valid, n - valid[i]);
  }
  return dp[n] = ans;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int p; cin >> p;
  while (p--) {
    int K, n, m, k;
    cin >> K >> n >> m >> k;
    cout << K << ' ';
    vector<int> invalid(n + 1);
    for (int i = 0; true; ++i) {
      int c = m + i * k;
      if (c > n) break;
      invalid[c] = true;
    }

    vector<int> valid;
    for (int i = 1; i <= n; ++i) {
      if (!invalid[i]) valid.push_back(i);
    }
    memset(dp, -1, sizeof dp);
    cout << go(valid, n) << endl;
  }
  return 0;
}
