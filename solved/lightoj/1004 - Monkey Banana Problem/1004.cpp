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
#define MP 102

int dp[2*MP][MP];
int data[2*MP][MP];
int n;


void read(){
    for(int j=0;j<n;++j)
        for(int k=0;k<=j;++k)
            scanf("%d",&data[j][k]);

    for(int j=n ;j < 2*n-1;++j)
       for(int k= 0; k<2*n-1-j;++k)
            scanf("%d",&data[j][k]);
}

int solve(){
    dp[0][1]= data[0][0];
    for(int j=1;j<n;++j)
        for(int k=0;k<=j;++k)
            dp[j][k+1] = data[j][k] + ((dp[j-1][k+1]<dp[j-1][k])?dp[j-1][k]:dp[j-1][k+1]);

    for(int j=n ;j < 2*n-1;++j)
       for(int k= 0; k<2*n-1-j;++k)
            dp[j][k+1] = data[j][k] + ((dp[j-1][k+1]<dp[j-1][k+2])?dp[j-1][k+2]:dp[j-1][k+1]);

    
    return dp[2*n -2][1];
}

int main(){
	int numcas;scanf("%d",&numcas);
    for(int i=1;i<=numcas;++i){
        scanf("%d",&n);
        for(int k=0;k<=2*n;++k){
            for(int j=0;j<=n;++j){
                data[k][j]=0;
            }
        }
        read();
        printf("Case %d: %d\n",i,solve());
//		cout<<"Case "<<i<<": "<<solve()<<endl;
	}
	return 0;
}
