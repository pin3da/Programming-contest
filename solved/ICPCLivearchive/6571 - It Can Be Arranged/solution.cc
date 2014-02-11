using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

// Max flow
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

// End of Max flow

int cn;
int start[MN];
int end[MN];
int students[MN];
int clean_time[MN][MN];
int names[MN][2];

void solve() {
  int n, m;
  cin>>n>>m;

  long long flow = 0;
  for (int i = 0; i < n; ++i) {
    cin>>start[i]>>end[i]>>students[i];
    flow += ((students[i] + m - 1) / m);
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin>>clean_time[i][j];

  long long low = 1, hi = flow;

  while (low < hi) {
    int mid = (low + hi) >> 1;

    Dinic graph(2*n + 10);
    int _id = 0;
    int source  = _id++;
    int source2 = _id++;
    int sink    = _id++;
    int sink2   = _id++;

    for (int i = 0; i < n; ++i) {
      names[i][0] = _id++;
      graph.AddEdge(source, names[i][0], (students[i] + m - 1) / m);
      graph.AddEdge(names[i][0], sink, INF);
    }

    for (int i = 0; i < n; ++i) {
      names[i][1] = _id++;
      graph.AddEdge(source2, names[i][1], INF);
      graph.AddEdge(names[i][1], sink2, (students[i] + m - 1) / m);
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if ((i != j) and (end[i] + clean_time[i][j] < start[j]))
          graph.AddEdge(names[i][0], names[j][1], INF);

    graph.AddEdge(sink,source2, mid);

    if (graph.GetMaxFlow(source, sink2) == flow) {
      hi = mid;
    } else {
      low = mid + 1;
    }
  }

  printf("Case %d: %lld\n", cn, low);

}

int main() {

  int tc;cin>>tc;
  for (cn = 1; cn <= tc; ++cn) {
    solve();
  }
  return 0;
}
