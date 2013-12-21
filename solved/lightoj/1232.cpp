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
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXNODES 1000

int coins[105];
int dp[10005];
int n,k;

const int mod = 100000007;

int solve(){

  dp[0]=1;
  
   for(int i=0; i<n; i++)
        for(int j=coins[i]; j<=k; j++){
            dp[j] += dp[j-coins[i]];
            dp[j] %= mod;
         }

  return dp[k];
  
  
}
int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
	    memset(dp,0,sizeof(dp));
        cin>>n>>k;
        for(int i=0;i<n;++i) cin>>coins[i];
		cout<<"Case "<<cid<<": "<<solve()<<endl;
	}
	return 0;
}
