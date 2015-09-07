using namespace std;
#include <bits/stdc++.h>
#define foreach(it, v) for(typeof v.begin() it = v.begin(); it != v.end(); ++it)

struct MCMF {
    typedef int ctype;
    enum { MAXN = 1000, INF = INT_MAX };
    struct Edge { int x, y; ctype cap, cost; };
    vector<Edge> E;      vector<int> adj[MAXN];
    int N, prev[MAXN];   ctype dist[MAXN], phi[MAXN];

    MCMF(int NN) : N(NN) {}

    void add(int x, int y, ctype cap, ctype cost) { // cost >= 0
        Edge e1={x,y,cap,cost}, e2={y,x,0,-cost};
        adj[e1.x].push_back(E.size()); E.push_back(e1);
        adj[e2.x].push_back(E.size()); E.push_back(e2);
    }

    pair<ctype, ctype> mcmf(int s, int t) {
        int x;
        ctype flowVal = 0;
        ctype flowCost = 0;  memset(phi, 0, sizeof(phi));
        while (true) {
            for (x = 0; x < N; x++) prev[x] = -1;
            for (x = 0; x < N; x++) dist[x] = INF;
            dist[s] = prev[s] = 0;

            set< pair<ctype, int> > Q;
            Q.insert(make_pair(dist[s], s));
            while (!Q.empty()) {
                x = Q.begin()->second; Q.erase(Q.begin());
                foreach(it, adj[x]) {
                    const Edge &e = E[*it];
                    if (e.cap <= 0) continue;
                    ctype cc = e.cost + phi[x] - phi[e.y];   // ***
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
            for (x = t; x != s; x = E[prev[x]].x)
                { z = min(z, E[prev[x]].cap); }
            for (x = t; x != s; x = E[prev[x]].x)
                { E[prev[x]].cap -= z; E[prev[x]^1].cap += z; }
            flowVal += z;
            flowCost += z * (dist[t] - phi[s] + phi[t]);
            for (x = 0; x < N; x++)
                { if (prev[x] != -1) phi[x] += dist[x]; }    // ***
        }
        return make_pair(flowVal, flowCost);
    }
};

void solve() {
  int n, k, g, t;
  cin >> n >> k >> g;
  int N = 2 * n;
  MCMF pos(N + 2), neg (N + 2);
  int source = N, sink = N + 1;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos.add(source, i, 1, 0);
    neg.add(source, i, 1, 0);
    pos.add(i + n, sink, 1, 0);
    neg.add(i + n, sink, 1, 0);
  }

  for (int i = 0; i < n; ++i) {
    cin >> t;
    for (int j = 0; j < n; ++j) {
      if (a[j] < t) {
        int q = t - a[j] - k;
        pos.add(j, i + n, 1, min(g, q * q));
        neg.add(j, i + n, 1, g - min(g, q * q));
      }
    }
  }

  pair<int, int> ans = pos.mcmf(source, sink);
  if (ans.first != n) {
    puts("impossible");
  } else {
    printf("%d %d\n", ans.second, g * n - neg.mcmf(source, sink).second);
  }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
