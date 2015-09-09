using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define foreach(it, b) for(typeof b.begin() it = b.begin(); it != b.end(); ++it)

typedef long long L;

struct MCMF {
  typedef long long ctype;
  enum { MAXN = 1000, INF = INT_MAX};
  struct edge {int x, y; ctype cap, cost;};
  vector<edge> E; vector<int> adj[MAXN];
  int N, prev[MAXN]; ctype dist[MAXN], phi[MAXN];
  MCMF(int NN) : N(NN) {}
  void addEdge(int x, int y, ctype cap, ctype cost) {
    edge e1 = {x, y, cap, cost}, e2 = {y, x, 0, -cost};
    adj[e1.x].push_back(E.size());E.push_back(e1);
    adj[e2.x].push_back(E.size());E.push_back(e2);
  }

  pair<L, L> mcmf(int s, int t) {
    int x;
    L flowVal = 0;
    L flowCost = 0; memset(phi, 0, sizeof phi);
    while (true) {
      for (int x = 0; x < N; ++x) prev[x] = -1;
      for (int x = 0; x < N; ++x) dist[x] = INF;
      dist[s] = prev[s] = 0;

      set<pair<ctype, int> > Q;
      Q.insert(make_pair(dist[s], s));
      while (!Q.empty()) {
        x = Q.begin() -> second; Q.erase(Q.begin());
        foreach(it, adj[x]) {
          const edge &e = E[*it];
          if (e.cap <= 0) continue;
          ctype cc = e.cost + phi[x] - phi[e.y];
          if (dist[x] + cc < dist[e.y]) {
            Q.erase(make_pair(dist[e.y], e.y));
            dist[e.y] = dist[x] + cc;
            prev[e.y] = *it;
            Q.insert(make_pair(dist[e.y], e.y));
          }
        }
      }
      if (prev[t] == -1) break;

      ctype z = INF;
      for (x = t; x != s; x = E[prev[x]].x) {
        z = min(z, E[prev[x]].cap);
      }
      for (x = t; x != s; x = E[prev[x]].x) {
        E[prev[x]].cap -= z; E[prev[x]^1].cap += z;
      }

      flowVal += z;
      flowCost += z * (dist[t] - phi[s] + phi[t]);
      for (int x = 0; x < N; ++x) {
        if (prev[x] != -1)
          phi[x] += dist[x];
      }
    }
    return make_pair(flowVal, flowCost);
  }

};

int main() {
  #ifdef TCBAHIA
  freopen("e.in", "r", stdin);
  #endif // TCBAHIA

  int n, m;
  while (cin >> n >> m) {
    int source = n + 1;
    // MinCostMaxFlow g(n + 10);
    MCMF g(n);
    int t;
    for (int i = 0; i < n - 1; ++i) {
      cin >> t;
      g.addEdge(source, i, t, 0);
    }

    int a,b, c;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> t >> c;
      //cout << "from " << a << " to " << b << endl;
      g.addEdge(a - 1, b - 1, t, c);
      g.addEdge(b - 1, a - 1, t, c);
    }
    pair<L, L> ans = g.mcmf(source, n - 1);
    cout << ans.first << " " << ans.second << endl;
  }

  return 0;
}
