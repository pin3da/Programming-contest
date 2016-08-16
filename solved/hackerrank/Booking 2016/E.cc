#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
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
    // cout << "added " << from << " to " << to << endl;
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

int get_id(map<string, int> &m, string &s) {
  if (m.count(s)) return m[s];
  int ans = m.size();
  return m[s] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  map<string, int> id;
  vector<int> tid(n);
  vector<set<int> > p(n);
  vector<set<int> > tp(n);
  for (int i = 0; i < n; ++i) {
    cin >> tid[i];
    tid[i]--;
    int t; cin >> t;
    for (int j = 0; j < t; ++j)  {
      string line; cin >> line;
      int q = get_id(id, line);
      p[i].insert(q);
    }
  }
  for (int i = 0; i < n; ++i) {
    int t; cin >> t;
    for (int j = 0; j < t; ++j)  {
      string line; cin >> line;
      int q = get_id(id, line);
      tp[i].insert(q);
    }
  }
  int source = 3 * n + id.size();
  int sink = source + 1;
  PushRelabel g(sink + 10);

  for (int i = 0; i < n; ++i) {
    g.AddEdge(source, i, 1);
    g.AddEdge(n + i, 2 * n + i, 1);
    for (set<int>::iterator it = tp[i].begin(); it != tp[i].end(); ++it) {
      g.AddEdge(2 * n + i, 3 * n + (*it), 1);
    }
  }
  for (map<string, int>::iterator it = id.begin(); it != id.end(); ++it) {
    g.AddEdge(3 * n + it-> second, sink, 10000);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (set<int>::iterator it = p[i].begin(); it != p[i].end(); ++it) {
        if (tp[j].count(*it)) {
          g.AddEdge(i, n + j, 1);
          break;
        }
      }
    }
  }

  cout << g.GetMaxFlow(source, sink) << endl;
  return 0;
}
