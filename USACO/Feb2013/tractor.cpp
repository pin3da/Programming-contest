 /*
ID: pin3da
PROG: tractor
LANG: C++
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
#include<set>

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
#define MP 510

struct point{
	int x,y;
	point() {}
	point(int X, int Y) : x(X), y(Y) {}
};

int grid[MP][MP];
int visited[MP][MP];
int mio[MP][MP][4]; //right,up,left,down
int dp[MP][MP]; //right,up,left,down
int n,n2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
point start;
set<int> diff;

void preprocess(){
    int mm = 1<<30;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<4;++k){
                if(i + dx[k] >= 0 and i + dx[k] < n and j + dy[k] >= 0 and j + dy[k] < n){
                    mio[i][j][k] = abs(grid[i][j] - grid[i+dx[k]][j+dy[k]]);
                    diff.insert(mio[i][j][k]);
                    if(mio[i][j][k] < mm){
                        mm = mio[i][j][k];
                        start = point(i,j);
                    }
                }
            }
        }
    }
}

int solve(int i,int j,int di){
    visited[i][j] = true;
    
    if(dp[i][j]) return dp[i][j];
    
    int pin = 1;
    for(int k=0;k<4;++k)
         if(i + dx[k] >= 0 and i + dx[k] < n and j + dy[k] >= 0 and j + dy[k] < n)
            pin &= dp[i + dx[k]][j + dy[k]];
    
    if(pin) return dp[i][j]=1;

    int m=0;
    for(int k=0;k<4;++k)
         if(i + dx[k] >= 0 and i + dx[k] < n and j + dy[k] >= 0 and j + dy[k] < n)
            if(fabs(grid[i][j] - grid[i+dx[k]][j+dy[k]]) <= di and !visited[i+dx[k]][j+dy[k]]){
                m = max(m,solve(i+dx[k],j+dy[k],di));
            }
         
    return dp[i][j]=(m+1);
}

int main(){
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>grid[i][j];
    
    n2 = (int)ceil(((n*n)/2.0));
    int ans = 1<<30;
    preprocess();
    
    foreach(d,diff){
        memset(dp,0,sizeof(dp));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(!visited[i][j]){
                    if(solve(i,j,(*d))>=n2){
                        ans = (*d);
                        break;
                    }
                }
            }
            if(ans != (1<<30)) break;
        }
        if(ans != (1<<30)) break;
    }
    
    cout<<ans<<"\n";
	return 0;
}
