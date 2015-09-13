#include<bits/stdc++.h>
using namespace std;

const long long inf = 1LL << 40;
typedef pair<long long, int> state;

long long dijkstra(vector<vector<pair<int, long long> > > &g, int s, int t) {
  vector<long long> d(g.size(), inf);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;

  d[s] = 0;
  q.push(state(0, s));

  while (!q.empty()) {
    int node = q.top().second;
    long long dist = q.top().first;
    q.pop();

    if (dist > d[node]) continue;

    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i].first;
      long long w_extra = g[node][i].second;
      if (dist + w_extra < d[to]) {
        d[to] = dist + w_extra;
        q.push(state(d[to], to));
      }
    }
  }

  return d[t];

}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<pair<int, long long> > > G(n);
    int u, v, w;
    for(int i = 0 ; i < m; i++){
      cin >> u >> v >> w;
      u--; v--;
      G[u].push_back(make_pair(v,w));
      G[v].push_back(make_pair(u,w));
    }
    vector<vector<pair<int, long long> > > Gn(n);

    for(int i = 0; i < n; i++){
      for(int j = 0; j < G[i].size();j++){
        int cur = G[i][j].first;
        for(int k = 0; k < G[cur].size(); k++){
          if (i == G[cur][k].first) continue;
          int cost = G[i][j].second + G[cur][k].second;
          Gn[i].push_back(make_pair(G[cur][k].first, cost));
          Gn[G[cur][k].first].push_back(make_pair(i, cost));
        }
      }
    }

    long long d = dijkstra(Gn, 0, n -1);
    if (d >= inf) {
      cout << -1 << endl;
    } else {
      cout << d << endl;
    }

  }
  return 0;
}
