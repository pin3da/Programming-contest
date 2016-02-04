#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge{
  int from, to;
  long long w;
  edge() {}
  edge(int a, int b, long long c) : from(a), to(b), w(c) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

const long long inf = 1 << 30;

typedef vector<vector<edge>> graph;
vector<long long> d;
vector<int> pi;
priority_queue<edge> q;


void dijkstra(graph &g) {

  while (!q.empty()) {
    edge cur = q.top();q.pop();
    long long dist = cur.w;
    int node = cur.to;

    if (dist == d[node])
    for (auto &e : g[node]) {
      if (dist + e.w < d[e.to]){
        d[e.to] = dist + e.w;
        pi[e.to] = node;
        q.push(edge(0, e.to, d[e.to]));
      }
    }
  }
}

void del_edge(graph &g, vector<vector<int>> &inv, int u, int v) {
  for (int i = 0; i < g[u].size(); ++i) {
    if (g[u][i].to == v) {
      g[u].erase(g[u].begin() + i);
      break;
    }
  }

  for (int i = 0; i < inv[v].size(); ++i) {
    if (inv[v][i] == u) {
      inv[v].erase(inv[v].begin() + i);
      break;
    }
  }
}

void clear_dist(graph &g, vector<vector<int>> &inv, int node) {
  if (d[node] == inf)
    return;

  d[node] = inf;

  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i].to;
    if(pi[to] == node)
      clear_dist(g, inv, to);
  }

  for (int i = 0; i < inv[node].size(); ++i) {
    int from = inv[node][i];
    q.push(edge(0, from, d[from]));
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    graph g(n);
    vector<vector<int>> inc(n);
    d.assign(n + 10, inf);
    pi.assign(n + 10, -1);
    q = priority_queue<edge>();

    int u, v, w;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> w;
      u--; v--;
      g[u].emplace_back(u, v, w);
      inc[v].emplace_back(u);
    }
    int tt;
    cin >> tt;
    char op;

    d[0] = 0;
    pi[0] = 0;
    q.push(edge(0, 0, 0));
    dijkstra(g);

    while (tt--) {
      cin >> op;
      if (op == 'P') {
        cin >> v;
        v--;
        if (d[v] < inf)
          cout << d[v] << endl;
        else
          cout << -1 << endl;
      }

      if (op == 'R') {
        cin >> u >> v;
        u--;v--;
        del_edge(g, inc, u, v);
        if (pi[v] == u) {
          clear_dist(g, inc, v);
          dijkstra(g);
        }
      }

      if (op == 'I') {
        cin >> u >> v >> w;
        u--;v--;
        g[u].emplace_back(u, v, w);
        inc[v].emplace_back(u);
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          pi[v] = u;

          q.push(edge(0, v, d[v]));
          dijkstra(g);
        }
      }
    }
    cout << endl;
  }
  return 0;
}
