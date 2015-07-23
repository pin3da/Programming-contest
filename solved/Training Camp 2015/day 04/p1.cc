using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MAXNODES = 10001;

struct edge{
  int to, weight;
  edge() {}
  edge(int t, int w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

// vector<edge> g[MAXNODES];
int d[MAXNODES]; //d[i] = distancia más corta desde s hasta i
int p[MAXNODES]; //p[i] = predecesor de i en la ruta más corta


int dijkstra(vector<vector<edge>> &g, int s, int t, int n){
  //s = nodo inicial, n = número de nodos
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

void solve(int n, int m) {
  vector<vector<edge>> g(n);
  vector<int> f(m), t(m), c(m);
  for (int i = 0; i < m; ++i) {
    cin >> f[i] >> t[i] >> c[i];
    g[f[i]].push_back(edge(t[i], c[i]));
    g[t[i]].push_back(edge(f[i], c[i]));
  }

  int best = dijkstra(g, 0, n - 1, n);
  vector<int> dist1(n), dist2(n);
  for (int i = 0; i < n; ++i) {
    dist1[i] = d[i];
  }
  dijkstra(g, n - 1, 0, n);
  for (int i = 0; i < n; ++i) {
    dist2[i] = d[i];
  }


  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int u = f[i], v = t[i], co = c[i];
    if ((dist1[u] + co + dist2[v] == best) ||
        (dist1[v] + co + dist2[u] == best)) {
      ans += 2 * co;
    }
  }

  cout << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
    solve(n, m);
  }
  return 0;
}
