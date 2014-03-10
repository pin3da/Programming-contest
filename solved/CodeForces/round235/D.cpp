using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 20

string line;
int mod;
int num[MN];
long long fact[MN];

long long dp[(1<<18)][100];

long long solve(int mask, int m) {

  if (mask == (1<<line.size()) -1 )  {
    return m == 0;
  }

  if(dp[mask][m] != -1) return dp[mask][m] ;
  long long ans = 0;

  for (int i = 0; i < line.size(); ++i) {
    if (mask & (1<<i)) continue;
    if (mask == 0 and num[i] == 0) continue;
    ans += solve(mask | (1<<i), ((num[i] + (m * 10) % mod) % mod));
  }

  return dp[mask][m] = ans;

}

int main() { ___

  cin>>line>>mod;



  vector<int> frec(10,0);
  for (int i = 0; i < line.size(); ++i){
    num[i] = line[i] - '0';
    frec[num[i]]++;
  }

  fact[0] = 1;
  for (int i = 1; i < MN; ++i) {
    fact[i] = fact[i-1] * i;
  }

  memset(dp, -1, sizeof dp);
  long long ans = solve(0,0);
  for (int i = 0; i < 10; ++i) {
    if (frec[i] == 0)  continue;
    ans /= fact[frec[i]];
  }

  cout<<ans<<endl;


  return 0;
}
