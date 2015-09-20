using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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

  void ClearFlow() {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < G[i].size(); ++j)
        G[i][j].flow = 0;

  }
};


struct floe {
  double x, y;
};

void solve() {
  int n, penguins = 0;
  double d;
  cin >> n >> d;
  vector<floe> f(n);
  double x, y;
  int  cap, cur;
  int source = 2 * n;
  Dinic g(source + 2);
  for (int i  = 0; i < n; ++i) {
    cin >> x >> y >> cur >> cap;
    penguins += cur;
    g.AddEdge(source, i, cur);
    g.AddEdge(i, i + n, cap);
    f[i] = (floe) {x, y};
    for (int j = 0; j < i; ++j) {
      double a = f[i].x - f[j].x;
      double b = f[i].y - f[j].y;
      if (cmp(a * a + b * b, d * d) != 1) {
        g.AddEdge(i + n, j, INF);
        g.AddEdge(j + n, i, INF);
      }
    }
  }
  int first = 1;
  for (int i = 0; i < n; ++i) {
    g.ClearFlow();
    if (g.GetMaxFlow(source, i) == penguins) {
      if (!first) printf(" ");
      printf("%d", i);
      first = 0;
    }
  }
  if (first)
    printf("-1");
  puts("");
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
