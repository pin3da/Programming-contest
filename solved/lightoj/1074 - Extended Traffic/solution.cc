using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<< #x " = " <<(x)<<endl
#define MN 222

int b[MN];
int g[MN][MN];
int d[MN];
int cycle[MN];

pair<int,int> edges[MN*MN];
int n,m;

const int inf = 20*20*20*50 + 10;

int cube(int x){
  return x*x*x;
}

void dfs(int u){
  if(cycle[u]) return;
  cycle[u] = true;
  For(i,n)if(g[u][i] != inf) dfs(i);
}

void bellman(int s){
  For(i,n) {
    d[i] = inf;
    cycle[i] = 0;
  }

  d[s] = 0;

  For(times,n-1){
    For(i,m){
      int u = edges[i].first;
      int v = edges[i].second;
      int w = g[u][v];
      if(d[u] < inf and d[u] + w < d[v]){
        d[v] = d[u] + w;
      }
    }
  }

  For(i,m){
    int u = edges[i].first;
    int v = edges[i].second;
    int w = g[u][v];
    if(d[u] < inf and d[u] + w < d[v] and !cycle[u])
      dfs(u);
  }

}


void solve(){

  cin>>n;
  For(i,n)
    cin>>b[i];

  cin>>m;
  int u,v;
  For(i,n)For(j,n) g[i][j] = inf;

  For(i,m){
    cin>>u>>v;
    u--;v--;
    edges[i] = make_pair(u,v);
    g[u][v] = cube(b[v] - b[u]);
  }

  int q;cin>>q;

  bellman(0);
  int t;
  For(i,q){
    cin>>t;t--;
    if(d[t] < 3 or cycle[t] or d[t] == inf)printf("?\n");
    else printf("%d\n",d[t]);
  }

}


int main(){ ___
  int tc;cin>>tc;
  for(int i = 0; i< tc; ++i){
    printf("Case %d:\n",i+1);
    solve();
  }
  return 0;
}
