#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MN = 105, MX = 10010;
const int oo = 10000000;

struct edge{
  int u, w, id;
  edge(){}
  edge(int a, int b, int c): u(a), w(b), id(c){}

  bool operator <(const edge &x) const{
    if(w != x.w)
      return w > x.w;
    return u < x.u;
  }
};


vector<edge> G[MN], GT[MX];
set<int> bad[MN][MN];
int w[MX];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, e, v, r, u;
  while (cin >> n) {
    int id = 1;
    for (int i = 0; i < n; i++) {
      cin >> e >> w[i];
      for (int j = 0; j < e; j++) {
        cin >> r >> u; u--;
        edge et(u, i, id);
        for (int k = 0; k < r; k++) {
          cin >> v; v--;
          bad[i][u].insert(v);
        }
        G[i].push_back(et);
        id++;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < G[i].size(); j++) {
        edge u = G[i][j];
        for (int k = 0; k < G[u.u].size(); k++) {
          edge v = G[u.u][k];
          if (bad[u.u][v.u].count(i)) continue;
          GT[u.id].push_back(edge(v.id, w[v.w], 0));
        }
        if (u.u == n - 1) {
          GT[u.id].push_back(edge(id, w[n - 1], 0));
        }
      }
    }
    for (int i = 0; i < G[0].size(); i++) {
      edge u = G[0][i];
      GT[0].push_back(edge(u.id, w[u.w], 0));
    }

    vector<int> dist(MX, oo);
    priority_queue<edge> PQ;
    dist[0] = 0;
    PQ.push(edge(0, 0, 0));
    while (!PQ.empty()) {
      int u = PQ.top().u;
      int we = PQ.top().w;
      PQ.pop();
      if (we > dist[u]) continue;
      for (int i = 0; i < GT[u].size(); i++) {
        int v = GT[u][i].u;
        int wx = GT[u][i].w;
        if (dist[v] > wx + we) {
          dist[v] = wx + we;
          PQ.push(edge(v, dist[v], 0));
        }
      }
    }
    if (dist[id] >= oo) cout << "impossible" << endl;
    else cout << dist[id] << endl;
  }
}
