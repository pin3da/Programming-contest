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

int dp[1001][1001];

int lcs(const string &a,const string &b){
    int n=a.size(),m=b.size();
    if(n==0 || m==0) return 0;
    for(int i=0;i<=n;++i)
        dp[i][0] = 0;
    for(int j=0;j<=m;++j)
        dp[0][j] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;++j)
            dp[i][j] = ((a[i-1]==b[j-1])?(dp[i-1][j-1]+1):(max(dp[i][j-1],dp[i-1][j])));
            
    return dp[n][m];
}

int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
        string cad,cad2;
        cin>>cad;
        cad2=cad;
        reverse(all(cad2));
		cout<<"Case "<<cid<<": "<<cad.size()-lcs(cad,cad2)<<endl;
	}
	return 0;
}
