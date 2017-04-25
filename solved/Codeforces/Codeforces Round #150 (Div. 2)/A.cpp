// http://codeforces.com/contest/244/problem/A

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

int used[30*30+1];
int main(){
    int n,k;cin>>n>>k;
    int num[k][n];
    memset(used,0,sizeof(used));
    memset(num,0,sizeof(num));
    int d;
    for(int i=0;i<k;++i){
        cin>>d;
        num[i][0]=d;
        used[d]=true;
    }
    int x=0,y=1;
    for(int i=1;i<=k*n;++i){
        if(used[i])continue;
        num[x][y]=i;
        y++;
        if(y==n){
            y=1;
            x++;
        }
    }
    
    for(int i=0;i<k;++i){
        for(int j=0;j<n;++j){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
