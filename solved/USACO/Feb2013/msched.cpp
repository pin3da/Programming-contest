 /*
ID: pin3da
PROG: msched
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
#define MP 10000

struct Node{
    int time;
    vector<int> ad,pi;
    Node(){}
    Node(int T):time(T){}
};


Node G[MP];
int vis[MP];

int fun(int s){
    if(vis[s]!= 0) return vis[s];
    
    if(G[s].pi.size()==0)
        return vis[s]=G[s].time;
    
    int m = -1;
    foreach(i,G[s].pi){
        m = max(m,fun((*i)));
    }
    
    return vis[s]=m+G[s].time;
    
}

int main(){
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i =0 ;i<n; ++i)
        cin>>G[i].time;
    
    int u,v;
    for(int i= 0; i<m;++i){
        cin>>u>>v;
        u--;v--;
        G[u].ad.push_back(v);
        G[v].pi.push_back(u);
    }
    set<int> start;
    for(int i=0;i<n;++i)
        if(G[i].ad.size()==0) start.insert(i);
    
    int ans = -1;
    memset(vis,0,sizeof(vis));
    foreach(i,start){
        ans =  max(ans,fun((*i)));
    }
    
    cout<<ans<<"\n";
	return 0;
}
