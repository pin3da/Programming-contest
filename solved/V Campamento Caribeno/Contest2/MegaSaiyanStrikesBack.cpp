using namespace std;
#include<bits/stdc++.h>

long long dp[5005];
long long mod = 1000000007;

int main() {

  int q;scanf("%d", &q);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i < 5003; i++) {
    dp[i] = 0;
    for (int j = 1; j < i; ++j)
      dp[i] = (dp[i] + ((dp[j] * dp[i - j]) % mod)) % mod;
  }
  dp[1] = 0;
  while(q--) {
    int n; scanf("%d",&n);
    cout<<dp[n]<<endl;

  }
  return 0;
}
