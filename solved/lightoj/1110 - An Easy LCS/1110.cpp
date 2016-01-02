using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

int dp[101][101];
string lex[101][101];

int lcs(const string &a,const string &b, string &ans){
  int n=a.size(),m=b.size();
  if(n==0 || m==0) return 0;
  for(int i=0;i<=n;++i){
    dp[i][0] = 0;
    lex[i][0].clear();
  }
  for(int j=0;j<=m;++j){
    dp[0][j] = 0;
    lex[0][j].clear();
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;++j){
      if(a[i-1]==b[j-1]){
        dp[i][j] = dp[i-1][j-1]+1;
        lex[i][j] = lex[i-1][j-1] + a[i-1];
      }
      else if(dp[i][j-1] > dp[i-1][j]){
        dp[i][j] = dp[i][j-1];
        lex[i][j] = lex[i][j-1];
      }else if(dp[i][j-1] < dp[i-1][j]){
        dp[i][j] = dp[i-1][j];
        lex[i][j] = lex[i-1][j];
      }else{
        dp[i][j] = dp[i-1][j];
        lex[i][j] = min(lex[i-1][j],lex[i][j-1]);
      }
    }
  }

  ans=lex[n][m];

  return dp[n][m];
}

int main(){
  int numcas;cin>>numcas;
  for(int cid=1;cid<=numcas;++cid){
    string a,b;cin>>a>>b;
    string ans;
    cout<<"Case "<<cid<<": "<<((lcs(a,b,ans)==0)?":(":ans)<<endl;
  }
  return 0;
}
