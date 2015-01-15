using namespace std;
#include <bits/stdc++.h>

typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
        Gap(dist[v]);
      else
        Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};


void build(int node, int col, PushRelabel &network, vector<vector<int> > &g, vector<int> &v) {
  if (v[node])
    return;

  v[node] = true;
  for (int i = 0; i < g[node].size(); ++i) {
    if (col == 0)
      network.AddEdge(node, g.size() + g[node][i], 100);
    build(g[node][i], col ^ 1, network, g, v);
  }

}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > G(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int source = 2 * n;
  int sink   = source + 1;
  PushRelabel network(sink + 1);

  for (int i = 0; i < n; ++i) {
    network.AddEdge(source, i, 1);
    network.AddEdge(n + i, sink, 1);
  }

  vector<int> visited(n, 0);
  for (int i = 0; i < n; ++i)
    if(!visited[i])
      build(i, 0, network, G, visited);

  printf("%d\n", n - network.GetMaxFlow(source, sink));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
