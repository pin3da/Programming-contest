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

const double pi=acos(-1);

struct point{
	int x,y;
	point() {}
	point(int X, int Y) : x(X), y(Y) {}
};


int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
	    int n;cin>>n;
	    int costs[n][3];
	    int dp[n+1][3];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;++i)
	        for(int j=0;j<3;++j)
	            cin>>costs[i][j];

        for(int j=0;j<3;++j){
            dp[0][j]=costs[0][j];
            costs[n][j]=0;
        }
        
        for(int i=1;i<=n;++i){
            for(int j=0;j<3;++j){
                int mini = (1<<30);
                for(int k=0;k<3;++k){
                    if(j!=k){
                        mini= min(mini,dp[i-1][k]);
                    }
                }

                dp[i][j]= costs[i][j]+mini;
                //D(dp[i][j]);
            }
        }
	    
		cout<<"Case "<<cid<<": "<<min(min(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	}
	return 0;
}
