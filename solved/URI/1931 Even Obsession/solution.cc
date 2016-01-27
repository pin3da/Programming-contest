#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long inf = 1000000000;
struct edge{
  int to;
  long long w;
  edge(int a, long long b) : to(a), w(b) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

typedef vector<vector<edge>> graph;

void dfs(graph &g, graph &g2, vector<int> &vi, int node) {
  if (vi[node]) return;
  vi[node] = true;
  for (auto &i : g[node]) {
    for (auto &j : g[i.to]) {
      g2[node].push_back(edge(j.to, i.w + j.w));
      dfs(g, g2, vi, j.to);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<edge>> g(n), g2(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;v--;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }
  vector<int> vi(n);
  dfs(g, g2, vi, 0);

  priority_queue<edge> q;
  vector<long long> d(n, inf);
  q.push(edge(0, 0));
  d[0] = 0;
  while (!q.empty()) {
    edge cur = q.top();q.pop();
    if (d[cur.to] > cur.w)
      continue;

    for (auto &v : g2[cur.to]) {
      int w_extra = cur.w + v.w;
      if (w_extra < d[v.to]) {
        d[v.to] = w_extra;
        q.push(edge(v.to, w_extra));
      }
    }
  }

  if (d[n - 1] < inf)
    cout << d[n - 1] << endl;
  else
    cout << -1 << endl;

  return 0;
}
