// http://codeforces.com/contest/401/problem/D

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 20

string line;
int mod;
int tope;
int num[MN];
int p10[MN];
long long fact[MN];

long long dp[(1<<18)][100];

int next_popcount(int n){
    int c = (n & -n);
    int r = n+c;
    return (((r ^ n) >> 2) / c) | r;
}

int main() { ___

  cin>>line>>mod;



  vector<int> frec(10,0);
  for (int i = 0; i < line.size(); ++i){
    num[i] = line[i] - '0';
    frec[num[i]]++;
  }

  fact[0] = 1;
  p10[0] = 1 % mod;
  for (int i = 1; i < MN; ++i) {
    fact[i] = fact[i-1] * i;
    p10[i] = (p10[i-1] * 10) % mod;
  }

  tope = (1<<line.size()) - 1;


  for (int i = 0; i < mod; ++i) dp[tope][i] = 0;
  dp[tope][0] = 1;

  for (int i = line.size() - 1; i >= 0; --i) {
    int mask = (1<<i) - 1;
    while(mask <= tope) {
      for (int m = 0; m < mod; m++){
        dp[mask][m] = 0;
        for (int j = 0; j < line.size(); ++j) {
          if (mask & (1<<j)) continue;
          if (mask == 0 and num[j] == 0) continue;
          dp[mask][m] += dp[mask | (1<<j)][( m + ((num[j] * p10[line.size() - 1 - i]) % mod) ) % mod];
        }
      }
      if (mask == 0) break;
      mask = next_popcount(mask);
    }
  }

  long long ans = dp[0][0];
  for (int i = 0; i < 10; ++i) {
    if (frec[i] == 0)  continue;
    ans /= fact[frec[i]];
  }

  cout<<ans<<endl;


  return 0;
}