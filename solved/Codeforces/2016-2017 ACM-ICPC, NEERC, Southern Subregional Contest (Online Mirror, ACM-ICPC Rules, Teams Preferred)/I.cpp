// http://codeforces.com/contest/730/problem/I

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define forall(it, x) for (typeof x.begin() it = x.begin(); it != x.end(); ++it)

struct MCMF {
  typedef int ctype;
  enum { MAXN = 3030, INF = INT_MAX };
  struct Edge { int x, y; ctype cap, cost; };
  vector<Edge> E;      vector<int> adj[MAXN];
  int N, prev[MAXN];   ctype dist[MAXN], phi[MAXN];

  MCMF(int NN) : N(NN) {}

  void add(int x, int y, ctype cap, ctype cost) { // cost >= 0
    Edge e1={x,y,cap,cost}, e2={y,x,0,-cost};
    adj[e1.x].push_back(E.size()); E.push_back(e1);
    adj[e2.x].push_back(E.size()); E.push_back(e2);
  }

  void mcmf(int s, int t, ctype &flowVal, ctype &flowCost) {
    int x;
    flowVal = flowCost = 0;  memset(phi, 0, sizeof(phi));
    while (true) {
      for (x = 0; x < N; x++) prev[x] = -1;
      for (x = 0; x < N; x++) dist[x] = INF;
      dist[s] = prev[s] = 0;

      set< pair<ctype, int> > Q;
      Q.insert(make_pair(dist[s], s));
      while (!Q.empty()) {
        x = Q.begin()->second; Q.erase(Q.begin());
        forall(it, adj[x]) {
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
  }
};

const int offset = 3003;

int x[3003], y[3003];
MCMF g(3030);
int ansp[3003], anss[3003];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> y[i];
  int source = n;
  int sink = source + 1;
  int p = sink + 1;
  int s = p + 1;

  g.add(p, sink, a, 0);
  g.add(s, sink, b, 0);

  for (int i = 0; i < n; ++i) {
    g.add(source, i, 1, 0);
    g.add(i, p, 1, offset - x[i]);
    g.add(i, s, 1, offset - y[i]);
  }

  int totflow = 0, totcost = 0;
  g.mcmf(source, sink, totflow, totcost);
  assert(totflow == a + b);
  totcost -= offset * totflow;
  totcost *= -1;
  cout << totcost << endl;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> &edge = g.adj[i];
    for (int e = 0; e < (int) edge.size(); ++e) {
      if (g.E[edge[e]].cap == 0) {
        if (g.E[edge[e]].y == p)
          ansp[s1++] = (i + 1);
        else if (g.E[edge[e]].y == s)
          anss[s2++] = (i + 1);
      }
    }
  }

  for (int i = 0; i < a; ++i) {
    if (i) cout << ' ';
    cout << ansp[i];
  }
  cout << endl;

  for (int i = 0; i < b; ++i) {
    if (i) cout << ' ';
    cout << anss[i];
  }
  cout << endl;

  return 0;
}
