using namespace std;
#include<bits/stdc++.h>

const int MN = 200200;
int a[MN];
int memo[MN][111];
int memo2[MN][111];
const int mod = 1000000007;
int n;
int p;

int dp(int i, int sum) {
  if (i == n or sum > 100) return 1;
  if (memo[i][sum] != -1) return memo[i][sum];
  return memo[i][sum] = (dp(i + 1, sum) + dp(i + 1, sum + p)) % mod;
}

int go(int i, int sum) {
  if (i == n or sum < 0) return 1;
  if (memo[i][sum] != -1) return memo[i][sum];
  return memo[i][sum] = (dp(i + 1, sum) + dp(i + 1, sum - p)) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;cin>>tc;
  while (tc--) {
    cin>>n;
    for (int i = 0; i < n; ++i) cin>>a[i];

    memset(memo, -1, sizeof memo);
    memset(memo2, -1, sizeof memo2);
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (p = 0; p < 101; ++p) {
        if (a[i] +  p <= 100)
          ans = (ans + dp(i + 1, a[i] + p)) % mod;
        else ans = (ans + 1) % mod;
        if (a[i] - p >= 0)
          ans = (ans + go(i + 1, a[i] - p)) % mod;
        else
          ans = (ans + 1) % mod;
      }
    }
    //ans = (1<<n) - 1 - ans
    cout<<ans<<endl;
  }


  return 0;
}
