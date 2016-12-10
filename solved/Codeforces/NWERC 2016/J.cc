#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

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
    for (int i = 0; i < (int)G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < (int)G[v].size(); i++) Push(G[v][i]);
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
    for (int i = 0; i < (int)G[s].size(); i++) {
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
    for (int i = 0; i < (int)G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

const int inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, s;
  cin >> n >> q >> s;

  vector<int> s_to_q(s);
  vector<int> q_cap(q);
  vector<int> d_cap(n);
  vector<vector<int> > gen(n, vector<int> (s));

  // id
  int cur = 0;
  int source = cur++;
  int sink = cur++;
  long long total = 0;

  vector<vector<int> > id_q_in(n, vector<int> (q));
  vector<vector<int> > id_q_out(n, vector<int> (q));
  vector<int> id_d(n);

  for (int i = 0; i < s; ++i) {
    cin >> s_to_q[i];
    s_to_q[i]--;
  }

  for (int i = 0; i < q; ++i)
    cin >> q_cap[i];

  for (int i = 0; i < n; ++i) {
    cin >> d_cap[i];
    id_d[i] = cur++;
    for (int j = 0; j < s; ++j) {
      cin >> gen[i][j];
      total += gen[i][j];
    }

    for (int j = 0; j < q; ++j) {
      id_q_in[i][j] = cur++;
      id_q_out[i][j] = cur++;
    }
  }

  PushRelabel g(cur + 10);

  for (int i = 0; i < n; ++i) {
    vector<int> inc(q);
    for (int j = 0; j < s; ++j) {
      inc[s_to_q[j]] += gen[i][j];
    }

    for (int j = 0; j < q; ++j) {
      // lo que se genera de los sensores a la cola j
      g.AddEdge(source, id_q_in[i][j], inc[j]);
      if (i + 1 < n) {
        // Lo que se queda en la cola
        g.AddEdge(id_q_out[i][j], id_q_in[i + 1][j], inf);
      }
      // Lo que se descarga en el momento i
      g.AddEdge(id_q_out[i][j], id_d[i], inf);

      // Cap de la cola j
      g.AddEdge(id_q_in[i][j], id_q_out[i][j], q_cap[j]);
    }

    // Cap de la descarga i
    g.AddEdge(id_d[i], sink, d_cap[i]);
  }

  long long flow = g.GetMaxFlow(source, sink);
  puts(flow == total ? "possible" : "impossible");

  return 0;
}
