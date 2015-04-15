using namespace std;
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'
typedef long long int lli;

lli dp[61][61];
string cad;

lli solve(int i,int j){
  if (dp[i][j]!=-1) return dp[i][j];
  if (i>j) return dp[i][j] = 0;
  if (i==j) return dp[i][j] = 1;
  //    if (cad[i]==cad[j]) return dp[i][j] = (2*solve(i+1,j-1)) + 1;
  dp[i][j] = solve(i,j-1) + solve(i+1,j) - solve(i+1,j-1);
  if (cad[i]==cad[j]) dp[i][j] += solve(i+1,j-1) + 1;
  return dp[i][j];
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;cin>>t;
  for(int id = 1;id <= t;++id ){
    cin>>cad;
    memset(dp,-1,sizeof(dp));
    printf("Case %d: %lld\n",id,solve(0,cad.size()-1));
  }

  return 0;
}
