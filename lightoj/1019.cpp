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
#define MP 101
 
long long int g[MP][MP];
 
int main(){
  int u,v,w;
  int numcas;cin>>numcas;
  for(int cid=1;cid<=numcas;++cid){
    int n,m;scanf("%d%d",&n,&m);
 
    for(int i=0;i < MP;++i)
            for(int j=0;j < MP;++j)
                if(i==j) g[i][j] = 0;
                else g[i][j] = (1<<30);
               
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        g[u][v] = min((long long int)w,g[u][v]);
        g[v][u] = min((long long int)w,g[u][v]);
    }
 
    for(int k=0;k < n;++k)
        for(int i=0;i < n;++i)
            for(int j=0;j < n;++j)
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
   
    if(g[0][n-1]==(1<<30))    
        cout<<"Case "<<cid<<": Impossible"<<endl;
    else
        cout<<"Case "<<cid<<": "<<g[0][n-1]<<endl;
  }
  return 0;
}

