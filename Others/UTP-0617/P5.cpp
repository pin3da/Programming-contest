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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 100

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

//Complejidad: O(V*E)

const int oo = 1000000000;

struct edge{
  int v;
  long long w; 
  edge(){} edge(int v, int w) : v(v), w(w) {}
};

vector<edge> g[MAXNODES];
int M[MAXNODES][MAXNODES];

long long d[MAXNODES][MAXNODES];
int p[MAXNODES];

int karp(int n){
    for(int i = 0;i<n;++i)
     if(!g[i].empty())
         g[n].push_back(edge(i,0));
    ++n;
    
    for(int i = 0;i<n;++i)
        fill(d[i],d[i]+(n+1),INT_MAX);
    
    d[n-1][0] = 0;
    
    for (int k = 1;k<=n;++k) for (int u = 0;u<n;++u){
        if(d[u][k-1]==INT_MAX) continue;
        
        for(int i = g[u].size()-1;i>=0;--i)
            d[g[u][i].v][k] = min(d[g[u][i].v][k],d[u][k-1]+g[u][i].w);
    }
    
    bool flag = true;
    
    for(int i = 0;i<n && flag;++i)
        if(d[i][n]!=INT_MAX)
            flag = false;
    
    if(flag){
        return true;
    }
    
    double ans = 1e15;
    
    for(int u = 0;u+1<n;++u){
        if(d[u][n]==INT_MAX) continue;
        double W = -1e15;
        
        for(int k = 0;k<n;++k)
            if(d[u][k]!=INT_MAX)
                W = max(W,(double)(d[u][n]-d[u][k])/(n-k));
        
        ans = min(ans,W);
    }
    
    printf("%.2lf\n",ans);
    
    return false;
}

int main(){
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc; ++tid){
        int n,m;cin>>n>>m;
        int u,v,w;
        For(i,MAXNODES)g[i].clear();
        For(i,m){
            cin>>u>>v>>w;
            u--;
            v--;
            g[u].push_back(edge(v,w));
            M[u][v] = w;
        }
        cout<<"Case #"<<tid<<": ";
        if(karp(n))
            cout<<"No cycle found."<<endl;
    }
    
    return 0; 
}
