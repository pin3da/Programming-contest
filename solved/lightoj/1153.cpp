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
#define MAXN 100

int cap[MAXN+1][MAXN+1], prev[MAXN+1];

vector<int> g[MAXN+1]; //Vecinos de cada nodo.
inline void link(int u, int v, int c)
{ cap[u][v] += c;cap[v][u] += c; g[u].push_back(v), g[v].push_back(u); }

/*
Notar que link crea las aristas (u, v) && (v, u) en el grafo
g. Esto es necesario porque el algoritmo de Edmonds-Karp
necesita mirar el "back-edge" (j, i) que se crea al bombear
flujo a través de (i, j). Sin embargo, no modifica
cap[v][u], porque se asume que el grafo es dirigido. Si es
no-dirigido, hacer cap[u][v] = cap[v][u] = c.
*/


int residual[MAXN+1][MAXN+1];
int fordFulkerson(int n, int s, int t){
  memcpy(residual, cap, sizeof cap);

  int ans = 0;
  while (true){
    fill(prev, prev+n, -1);
    queue<int> q;
    q.push(s);
    while (q.size() && prev[t] == -1){
      int u = q.front();
      q.pop();
      vector<int> &out = g[u];
      for (int k = 0, m = out.size(); k<m; ++k){
        int v = out[k];
        if (v != s && prev[v] == -1 && residual[u][v] > 0)
          prev[v] = u, q.push(v);
      }
    }

    if (prev[t] == -1) break;

    int bottleneck = INT_MAX;
    for (int v = t, u = prev[v]; u != -1; v = u, u = prev[v]){
      bottleneck = min(bottleneck, residual[u][v]);
    }
    for (int v = t, u = prev[v]; u != -1; v = u, u = prev[v]){
      residual[u][v] -= bottleneck;
      residual[v][u] += bottleneck;
    }
    ans += bottleneck;
  }
  return ans;
}



int main(){
  int numcas;cin>>numcas;
  for(int cid=1;cid<=numcas;++cid){
    for(int i=0;i<=MAXN;++i){
      g[i].clear();
      for(int j=0;j<=MAXN;++j)cap[i][j]=0;
    }
    int n;cin>>n;
    int s,t,c;cin>>s>>t>>c;
    int u,v,w;
    while(c--){
      cin>>u>>v>>w;
      u--;v--;
      link(u,v,w);
    }
    s--;t--;
    int ans = fordFulkerson(n,s,t);
    cout<<"Case "<<cid<<": "<<ans<<endl;
  }
  return 0;
}
