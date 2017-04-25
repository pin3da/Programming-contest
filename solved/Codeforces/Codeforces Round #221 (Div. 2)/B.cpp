// http://codeforces.com/contest/376/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 111

struct edge{
  int to,w;
  edge(int a, int b): to(a),w(b){}
};

vector<edge> g[MP];
int inc[MP];
int out[MP];
int visited[MP];
int n,m;


int main(){ ___

  while(cin>>n>>m){
    for(int i = 0; i< MP; ++i){ g[i].clear();inc[i]=0;}
    memset(out,0,sizeof out);
    for (int i = 0; i < m; ++i) {
      int u,v,w;
      cin>>u>>v>>w;
      u--;v--;
      g[u].push_back(edge(v,w));
      inc[v] += w;
      out[u] += w;
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
      if(out[i] == 0) continue;
      if(inc[i] > out[i]) continue;
      ans += (out[i] - inc[i]);
    }
    cout<<ans<<'\n';

  }
  return 0;
}