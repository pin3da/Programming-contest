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

int get_id(unordered_map<string, int> &id, string &line) {
  if (id.count(line))
    return id[line];
  int ans = id.size();
  return id[line] = ans;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int s, r, f, t;
  while (cin >> s >> r >> f >> t) {
    int source = s + t + t;
    int sink = source + 1;
    PushRelabel g(sink + 10);
    unordered_map<string, int> id;
    string tmp;
    for (int i = 0; i < r; ++i) {
      cin >> tmp;
      g.AddEdge(source, get_id(id, tmp), 1);
    }
    for (int i = 0; i < f; ++i) {
      cin >> tmp;
      g.AddEdge(get_id(id, tmp), sink, 1);
    }
    for (int i = 0; i < t; ++i) {
      int in = (i << 1) + s,
          out = (i << 1 | 1) + s;
      int n; cin >> n;
      g.AddEdge(in, out, 1);
      for (int j = 0; j < n; ++j) {
        cin >> tmp;
        int dest = get_id(id, tmp);
        g.AddEdge(dest, in, 1);
        g.AddEdge(out, dest, 1);
      }
    }
    cout << g.GetMaxFlow(source, sink) << endl;
  }
  return 0;
}

