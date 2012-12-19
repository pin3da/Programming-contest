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
#define MAX(a,b) ((a>b)?(a):(b))

int dp[60][60][60];

int lcs(const string &s, const string &t,const string &u){
  int m = s.size(), n = t.size(), p = u.size();
  if (m == 0 || n == 0 || p ==0) return 0;
  for (int i=0; i<=m; ++i)
    dp[i][0][0] = 0;
  for (int j=0; j<=n; ++j)
    dp[0][j][0] = 0;
  for (int k=0; k<=p; ++k)
    dp[0][0][k] = 0;
    
    
  for (int i=0; i<m; ++i)
    for (int j=0; j<n; ++j)
       for (int k=0; k<=p; ++k)
            if (s[i] == t[j] && s[i]==u[k])
                dp[i+1][j+1][k+1] = dp[i][j][k]+1;
            else
                dp[i+1][j+1][k+1] = MAX(MAX(dp[i+1][j+1][k], dp[i][j+1][k+1]), dp[i+1][j][k+1]);
                
  return dp[m][n][p];
}

int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
	    string a,b,c;
        cin>>a>>b>>c;
        cout<<"Case "<<cid<<": "<<lcs(a,b,c)<<endl;   
	}
	return 0;
}
