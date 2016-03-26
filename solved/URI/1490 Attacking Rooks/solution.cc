#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
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

void mark_col(vector<string> &g, vector<vector<int>> &id_col, int &cur) {
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    int last = 0;
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == 'X') {
        for (int k = last; k < j; ++k) {
          id_col[i][k] = cur;
        }
        cur++;
        last = j;
      }
    }
    for (int k = last; k < n; ++k) {
      id_col[i][k] = cur;
    }
    cur++;
  }
}

void mark_row(vector<string> &g, vector<vector<int>> &id_row, int &cur) {
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    int last = 0;
    for (int j = 0; j < n; ++j) {
      if (g[j][i] == 'X') {
        for (int k = last; k < j; ++k) {
          id_row[k][i] = cur;
        }
        cur++;
        last = j;
      }
    }
    for (int k = last; k < n; ++k) {
      id_row[k][i] = cur;
    }
    cur++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<string> g(n);
    for (auto &i : g) cin >> i;
    vector<vector<int>> id_col(n, vector<int>(n));
    vector<vector<int>> id_row(n, vector<int>(n));
    int cur = 0;
    mark_col(g, id_col, cur);
    mark_row(g, id_row, cur);
    int source = cur++;
    int sink = cur++;
    PushRelabel flow(cur);
    set<int> rows, cols;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == '.') {
          flow.AddEdge(id_col[i][j], id_row[i][j], 1);
        }
        rows.insert(id_row[i][j]);
        cols.insert(id_col[i][j]);
      }
    }
    for (auto &i : cols)
      flow.AddEdge(source, i, 1);
    for (auto &i : rows)
      flow.AddEdge(i, sink, 1);

    cout << flow.GetMaxFlow(source, sink) << endl;
  }
  return 0;
}
