using namespace std;
#include <bits/stdc++.h>

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

map<string, int> cod;

void solve() {
  int col, n;
  cin >> col >> n;
  int source = 6 + n;
  int sink   = source + 1;
  Dinic g(sink + 2);
  for (int i = 0; i < 6; ++i)
    g.AddEdge(source, n + i, col);

  string a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    g.AddEdge(n + cod[a], i, 1);
    g.AddEdge(n + cod[b], i, 1);
    g.AddEdge(i, sink, 1);
  }

  if (g.GetMaxFlow(source, sink) == n)
    puts("YES");
  else
    puts("NO");

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cod["XXL"] = 0;
  cod["XL"]  = 1;
  cod["L"]   = 2;
  cod["M"]   = 3;
  cod["S"]   = 4;
  cod["XS"]  = 5;
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
