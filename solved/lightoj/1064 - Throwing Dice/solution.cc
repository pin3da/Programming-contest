using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

unsigned long long p6 [] = { 1LL, 6LL, 36LL, 216LL, 1296LL, 7776LL, 46656LL, 279936LL, 1679616LL, 10077696LL,
                    60466176LL, 362797056LL, 2176782336LL, 13060694016LL, 78364164096LL,
                    470184984576LL, 2821109907456LL, 16926659444736LL, 101559956668416LL,
                    609359740010496LL, 3656158440062976LL, 21936950640377856LL,
                    131621703842267136LL, 789730223053602816LL, 4738381338321616896LL };

void solve() {
  int n, x;
  cin >> n >> x;
  vector<vector<unsigned long long> >  dp(n + 1, vector<unsigned long long> (x + 1, 0));
  dp[0][x] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= x; ++j)
      for (int k = 1; k <= 6; ++k) {
        int next = min(j + k, x);
        dp[i][j] += dp[i - 1][next];
      }
  unsigned long long g = __gcd(dp[n][0], p6[n]);
  if (dp[n][0] % p6[n] == 0)
    cout << dp[n][0] / p6[n] << endl;
  else
    cout << dp[n][0] / g << "/" <<  p6[n] / g << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case " << i + 1 << ": ";
    solve();
  }
}
