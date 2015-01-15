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

int dx [] = {1, -1, 0, 0};
int dy [] = {0, 0, 1, -1};

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<char> > board(m, vector<char> (n));
  vector<vector<int> > id(m, vector<int> (n, -1));
  vector<int> col(2, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      if (board[i][j] != '*') continue;
      id[i][j] = col[(i + j) & 1];
      col[(i + j) & 1]++;
    }
  }

  int N = col[0] + col[1];
  int source = N + 1;
  int sink   = source + 1;

  PushRelabel graph(sink + 1);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] != '*') continue;
      if ((i + j) & 1)
        graph.AddEdge(source, id[i][j], 1);
      else
        graph.AddEdge(col[1] + id[i][j], sink, 1);
    }
  }


  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == '*' and ((i + j) & 1)) {
        for (int k = 0; k < 4; ++k) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 and x < m and y >= 0 and y < n and board[x][y] == '*') {
            graph.AddEdge(id[i][j], col[1] + id[x][y], 100);
          }
        }
      }
    }
  }

  printf("%d\n", N - graph.GetMaxFlow(source, sink));
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
