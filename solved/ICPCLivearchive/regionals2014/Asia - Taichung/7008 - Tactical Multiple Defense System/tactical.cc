#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

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

struct entry{
  int r, t, s;
};

int get_id(map<pair<int, int>, int> &d, pair<int, int> a) {
  if (d.count(a)) return d[a];
  int s = d.size();
  return d[a] = s;
}


int get_id(map<int, int> &d, int a) {
  if (d.count(a)) return d[a];
  int s = d.size();
  return d[a] = s;
}

void solve() {
  int n; cin >> n;
  PushRelabel g(n * 2 + 10);
  vector<entry> a(n);
  int source = 2 * n + 1;
  int sink   = source + 1;
  int j = 0;
  map<pair<int, int>, int> d;
  map<int, int> d2;
  for (auto &i : a) {
    cin >> i.r >> i.t >> i.s;
    int gcd = __gcd(i.t, i.s);
    i.t /= gcd;
    i.s /= gcd;
    g.AddEdge(get_id(d2, i.r), n + get_id(d, make_pair(i.s, i.t)), 1);
    j++;
  }

  for (int i = 0; i < d2.size(); ++i)
    g.AddEdge(source, i, 1);

  for (int i = 0; i < d.size(); ++i)
    g.AddEdge(n + i, sink, 1);

  cout << g.GetMaxFlow(source, sink) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
