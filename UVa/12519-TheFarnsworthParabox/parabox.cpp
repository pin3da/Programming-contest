/**
* Manuel Pineda
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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 110

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int oo = 1000000000;
struct edge{
  int v, w; edge(){} edge(int v, int w) : v(v), w(w) {}
};
vector<edge> g[MAXNODES];

int d[MAXNODES];
int p[MAXNODES];
// Retorna falso si hay un ciclo de costo negativo alcanzable
// desde s. Si retorna verdadero, entonces d[i] contiene la
// distancia más corta para ir de s a i. Si se quiere
// determinar la existencia de un costo negativo que no
// necesariamente sea alcanzable desde s, se crea un nuevo
// nodo A y nuevo nodo B. Para todo nodo original u se crean
// las aristas dirigidas (A, u) con peso 1 y (u, B) con peso
// 1. Luego se corre el algoritmo de Bellman-Ford iniciando en
// A.
bool bellman(int s, int n){
  for (int i=0; i<n; ++i){
    d[i] = oo;
    p[i] = -1;
  }

  d[s] = 0;
  for (int i=0, changed = true; i<n-1 && changed; ++i){
    changed = false;
    for (int u=0; u<n; ++u){
      for (int k=0; k<g[u].size(); ++k){
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]){
          d[v] = d[u] + w;
          p[v] = u;
          changed = true;
        }
      }
    }
  }

  for (int u=0; u<n; ++u){
    for (int k=0; k<g[u].size(); ++k){
      int v = g[u][k].v, w = g[u][k].w;
      if (d[u] + w < d[v]){
        //Negative weight cycle!

        //Finding the actual negative cycle. If not needed
        //return false immediately.
        return false;
      }
    }
  }
  return true;
}
int main(){
    int n,m;
    while(cin>>n>>m and (n+m)){
        int u,v,w;
        For(i,MAXNODES)g[i].clear();
        For(i,m){
            cin>>u>>v>>w;
            u--;
            v--;
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,-w));
        }
        if(bellman(0,n))
            cout<<"N"<<endl;
        else
            cout<<"Y"<<endl;
    }

    
    return 0; 
}

