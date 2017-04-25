// http://codeforces.com/contest/431/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 10001;

int n,k,d;

const long long mod = 1000000007;

long long memo[111][2];

long long dp(int sum, int toma) {
  if (sum > n) return 0;
  if (sum == n) {
    if (toma) return 1;
    return 0;
  }

  if (memo[sum][toma] != -1) return memo[sum][toma];
  long long ans = 0;

  for (int i = 1; i <= k; ++i)
    ans = (ans + dp(sum + i, toma or (i >= d))) % mod;

  return memo[sum][toma] = ans;
}

int main() { ___

  cin>>n>>k>>d;

  memset(memo, -1, sizeof memo);
  cout<<dp(0,0)<<endl;

  return 0;
}

