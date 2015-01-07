using namespace std;
#include <bits/stdc++.h>

typedef long double ld;

const ld inf = 1e100;

struct edge {
  int to;
  ld p;
  edge() {}
  edge(int a, ld b) : to(a), p(b) {}
  bool operator < (const edge &o) const {
    return p < o.p;
  }
};

void dijkstra(vector<vector<edge> > &g, vector<int> &pi) {
  int n = g.size();

  pi.assign(n, -1);
  vector<ld> d(n, 0);
  priority_queue<edge> q;
  q.push(edge(0, 1.0));
  d[0] = 1.0;
  while (!q.empty()) {
    int cur = q.top().to;
    ld dis = q.top().p;
    q.pop();

    // if (dis < d[cur]) continue;
    // if (cur == (n - 1)) return dis;

    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i].to;
      ld w_extra = g[cur][i].p;
      if (d[cur] * w_extra > d[to]) {
        d[to]  = d[cur] * w_extra;
        pi[to] = cur;
        q.push(edge(to, d[to]));
      }
    }
  }
  // return 0;
}

void solve() {
  int n, m, s, k;
  cin >> n >> m >> s >> k;
  int u, v, p;
  vector<vector<edge> > g(n);
  vector<vector<long double> > prob(n, vector<long double>(n, 0));
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> p;
    g[u].push_back(edge(v, p / 100.0));
    g[v].push_back(edge(u, p / 100.0));
    prob[u][v] = prob[v][u] = p / 100.0;
  }

  vector<int> pi;
  // ld ans = dijkstra(g, pi);
  dijkstra(g, pi);

  int node = n - 1;
  long double ans = 1;
  while (pi[node] != -1) {
    ans *= prob[node][pi[node]];
    node = pi[node];
  }

  // cout << ans << endl;
  double exp = (1.0 / ans ) * (s * 2 * k);
  printf("%.10lf\n", exp + 1e-9);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
