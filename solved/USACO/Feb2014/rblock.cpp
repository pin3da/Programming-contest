using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 256

struct edge{
  int to, weight;
  edge() {}
  edge(int t, int w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

vector<edge> g[MN];
int invg[MN][MN];

int d[MN];
int p[MN];


int dijkstra(int s, int t, int n){
  for (int i=0; i<n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }
  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()){
    int node = q.top().to;
    int dist = q.top().weight;
    q.pop();

    if (dist > d[node]) continue;
    if (node == t){
      //dist es la distancia más corta hasta t.
      //Para reconstruir la ruta se pueden seguir
      //los p[i] hasta que sea -1.
      return dist;
    }

    for (int i=0; i<g[node].size(); ++i){
      int to = g[node][i].to;
      int w_extra = g[node][i].weight;

      if (dist + w_extra < d[to]){
        d[to] = dist + w_extra;
        p[to] = node;
        q.push(edge(to, d[to]));
      }
    }
  }
  return INT_MAX;
}

int main() {


  freopen("rblock.in","r", stdin);
  freopen("rblock.out","w", stdout);


  int nodes, edges;
  cin>>nodes>>edges;
  for (int i = 0;i < edges; ++i) {
    int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
    invg[u][v] = g[u].size() - 1;
    invg[v][u] = g[v].size() - 1;
  }


  int best = dijkstra(0, nodes - 1, nodes);

  int act = nodes - 1;
  deque<int> path;
  while (act != -1) {
    path.push_front(act);
    act = p[act];
  }

  int ans = best;
  for (int i = 0; i < path.size() - 1; ++i) {
    int u = path[i];
    int v = path[i+1];
    int w = g[u][invg[u][v]].weight;

    g[u][invg[u][v]].weight = 2*w;
    g[v][invg[v][u]].weight = 2*w;

    int otro = dijkstra(0, nodes - 1, nodes);

    ans = max (ans, otro);

    g[u][invg[u][v]].weight = w;
    g[v][invg[v][u]].weight = w;

  }

  printf("%d\n", ans - best);

  return 0;
}
