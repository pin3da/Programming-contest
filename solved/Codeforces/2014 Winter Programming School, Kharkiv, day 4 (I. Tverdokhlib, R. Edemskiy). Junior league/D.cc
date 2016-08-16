#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

struct edge {
  int to;
  long long w;
  edge(int a, long long b) : to(a), w(b) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

typedef vector<vector<edge> > graph;

vector<edge> cur;

const int MN = 1001;
long long dp[MN];

long long subsize(graph &g, vector<long long> &p, int node, int pi) {
  if (dp[node] != -1) return dp[node];
  long long ans = p[node];
  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i].to;
    if (to != pi) {
      ans += subsize(g, p, to, node);
    }
  }
  return dp[node] = ans;
}

void dfs(graph &g, vector<long long> &p, int node, int pi) {

  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i].to;
    long long w = g[node][i].w;
    if (to != pi) {
      cur.push_back(edge(to, w * subsize(g, p, to, node)));
      dfs(g, p, to, node);
    }
  }
}


long long solve(vector<long long> &p, graph &g, int root, int k) {

  cur.clear();
  memset(dp, -1, sizeof dp);
  dfs(g, p, root, root);

  sort(cur.rbegin(), cur.rend());
  assert(cur.size() == (g.size() - 1));
  long long total = 0;
  for (int i = k; i < cur.size(); ++i) {
    total += cur[i].w;
  }
  return total;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, k;
  while (cin >> n >> k) {
    vector<long long> p(n);
    for (int i = 0; i < n; ++i)
      cin >> p[i];

    graph g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      u--;v--;
      g[u].push_back(edge(v, w));
      g[v].push_back(edge(u, w));
    }
    long long best = 1LL << 60;
    for (int i = 0; i < n; ++i) {
      best = min(best, solve(p, g, i, k));
    }
    cout << best << endl;
  }
  return 0;
}
