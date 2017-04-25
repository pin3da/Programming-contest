// http://codeforces.com/contest/543/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
long long mod;
int n, b, m;

const int MN = 501;
long long dp[MN][MN];

long long go(vector<int> &a) {
  dp[0][0] = 1;
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = a[i]; k <= b; ++k)
        dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
    }
  }

  long long ans = 0;
  for (int i = 0; i <= b; ++i)
    ans = (ans + dp[m][i]) % mod;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cin >> n >> m >> b >> mod;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  memset(dp, 0, sizeof dp);
  cout << go(a) << endl;
  return 0;
}
