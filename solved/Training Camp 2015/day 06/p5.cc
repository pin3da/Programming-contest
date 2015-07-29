using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
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


int r, c;

bool valid(int i, int j) {
  return i >=0 && i < r && j >= 0 && j < c;
}
void solve() {
  cin >> r >> c;
  vector<vector<char>> g(r, vector<char>(c));
  PushRelabel flow(r * c * 4 + 10);
  int source = 0;
  int sink   = source + 1;
  int need = 0;
  int _id   =  sink + 1;
  int id[r][c][4];

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> g[i][j];
      id[i][j][0] = _id++;
      id[i][j][1] = _id++;
      id[i][j][2] = _id++;

      if (g[i][j] == 'B') {
        // flow.AddEdge(source, id[i][j][0], 1);
        need++;
      } else if (g[i][j] == 'W') {
        flow.AddEdge(source, id[i][j][0], 1);
        flow.AddEdge(id[i][j][2], sink, 1);
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (g[i][j] == 'B') {
        if (valid(i - 1, j) && valid(i, j - 1)) {
          if (g[i - 1][j] == 'W' && g[i][j - 1]) {
            flow.AddEdge(id[i - 1][j][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j - 1][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j][1], id[i - 1][j][2], 1);
            flow.AddEdge(id[i][j][1], id[i][j - 1][2], 1);
          }
        }
        if (valid(i + 1, j) && valid(i, j - 1)) {
          if (g[i + 1][j] == 'W' && g[i][j - 1] == 'W') {
            flow.AddEdge(id[i + 1][j][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j - 1][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j][1], id[i + 1][j][2], 1);
            flow.AddEdge(id[i][j][1], id[i][j - 1][2], 1);

          }
        }

        if (valid(i + 1, j) && valid(i, j - 1)) {
          if (g[i + 1][j] == 'W' && g[i][j - 1]) {
            flow.AddEdge(id[i + 1][j][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j - 1][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j][1], id[i + 1][j][2], 1);
            flow.AddEdge(id[i][j][1], id[i][j - 1][2], 1);
          }
        }
        if (valid(i + 1, j) && valid(i, j + 1)) {
          if (g[i + 1][j] == 'W' && g[i][j + 1] == 'W') {
            flow.AddEdge(id[i + 1][j][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j + 1][0], id[i][j][1], 1);
            flow.AddEdge(id[i][j][1], id[i + 1][j][2], 1);
            flow.AddEdge(id[i][j][1], id[i][j + 1][2], 1);
          }
        }
      }
    }
  }

  if (flow.GetMaxFlow(source, sink) == 2 * need) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
