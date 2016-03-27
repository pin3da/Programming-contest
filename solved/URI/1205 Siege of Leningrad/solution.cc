#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct state{
  int node;
  long long cost;
  state() {}
  state(int a, long long b) : node(a), cost(b) {}
  bool operator < (const state & o) const {
    return cost > o.cost;
  }
};

typedef vector<vector<int>> graph;

double P;

const long long inf = 1LL << 45;
long long dfs(graph &g, vector<long long> &d, vector<int> &e, const int &tar, int node) {

  fill(d.begin(), d.end(), inf);
  priority_queue<state> q;
  q.push(state(node, e[node]));
  d[node] = e[node];
  while (!q.empty()) {
    int cur = q.top().node;
    long long cost = q.top().cost;
    q.pop();
    if (cost > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i];
      long long n_cost = cost + e[to];
      if (n_cost < d[to]) {
        d[to] = n_cost;
        q.push(state(to, n_cost));
      }
    }
  }
  return d[tar];
}


double go(int e, int k) {
  if (k < e) return 0;
  double ans = 1;
  while (e-- > 0) ans *= P;
  return ans + 1e-9;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cout << fixed << setprecision(3);
  int n, m, k;
  while (cin >> n >> m >> k >> P) {
    graph g(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      u--;v--;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    int enemies;
    cin >> enemies;
    vector<int> e(n);
    for (int i = 0; i < enemies; ++i) {
      int t;cin >>t;
      e[t - 1]++;
    }
    int start, end;
    cin >> start >> end;
    start--;end--;
    vector<long long> d(n);
    long long min_e = dfs(g, d, e, end, start);
    if (min_e >= inf)
      cout << 0.000 << endl;
    else
      cout << go(min_e, k) << endl;
  }

  return 0;
}
