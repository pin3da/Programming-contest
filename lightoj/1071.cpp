/**
* Solution based on the post of Leonardo Boshell: http://lbv-pc.blogspot.com/search/label/dynamic%20programming
*/

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
#define Dbg if(1)
#define MAXNODES 1000

int data[105][105];
int dp[105][105][105];
int m,n;

int solve(){
  dp[1][1][2] = data[1][1] + data[1][2];
  for(int i=3;i<=n;++i) dp[1][1][i] = dp[1][1][i-1] + data[1][i];
  

  for(int i = 2; i<=m ;++i){
    for(int j=1;j<=n;++j)
      for(int k=j+1; k<=n;++k)
            dp[i][j][k] = dp[i-1][j][k] + data[i][j] + data[i][k];

 
    for(int j=1;j<n;++j)
      for(int k=j+1; k<=n;++k)
        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + data[i][j]) ;
 
 
    for(int j=1;j<n-1;++j)
      for(int k=j+2; k<=n;++k)
        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1] + data[i][k]) ;
 
  }
  
  return dp[m][n-1][n];
}

int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
    cin>>m>>n;
    for(int i=0;i< m ;++i )
      for(int j =0;j< n;++j)
        cin>>data[i+1][j+1];
        
		cout<<"Case "<<cid<<": "<<solve()<<endl;
	}
	return 0;
}
