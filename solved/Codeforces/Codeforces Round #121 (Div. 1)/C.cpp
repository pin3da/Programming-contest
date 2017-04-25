// http://codeforces.com/contest/191/problem/C

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MAXN = 1e5 + 10;
const int MLOG = 18;
int p[MAXN][MLOG];
int sum[MAXN][MLOG];
int id[MAXN];
int level[MAXN];

struct edge {
  int to, id;
  edge(int a, int b) : to(a), id(b) {}
};

typedef vector<vector<edge> > graph;

void dfs(graph &g, int node, int pi) {
  for (size_t i = 0; i < g[node].size(); ++i) {
    int to = g[node][i].to;
    if (to != pi) {
      level[to] = level[node] + 1;
      p[to][0] = node;
      id[g[node][i].id] = to;
      dfs(g, to, node);
    }
  }
}


int query(int u, int v) {
  if (level[u] < level[v])
    swap(u, v);
  int lg;
  for (lg = 1; 1 << lg <= level[u]; ++lg);lg--;
  for (int i = lg; i >= 0; --i)
    if (level[u] - (1 << i) >= level[v]) {
      sum[u][i]++;
      u = p[u][i];
    }

  if (u == v) {
    return u;
  }

  for (int i = lg; i >= 0; --i) {
    if (p[u][i] != -1 && p[u][i] != p[v][i]) {
      sum[u][i]++;
      sum[v][i]++;
      u = p[u][i];
      v = p[v][i];
    }
  }
  assert(p[u][0] == p[v][0]);
  sum[u][0]++; sum[v][0]++;
  return p[u][0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    graph g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; cin >> u >> v; u--;v--;
      g[u].push_back(edge(v, i));
      g[v].push_back(edge(u, i));
    }
    memset(p, -1, sizeof p);
    memset(level, -1, sizeof level);
    memset(sum, 0, sizeof sum);
    level[0] = 0;
    dfs(g, 0, -1);
    for (int j = 1; j < MLOG; ++j)
      for (int i = 0; i < n; ++i)
        if (p[i][j - 1] != -1)
          p[i][j] = p[p[i][j - 1]][j - 1];

    int k; cin >> k;
    while (k--) {
      int u, v; cin >> u >> v; u--;v--;
      query(u, v);
    }
    for (int j = MLOG - 1; j > 0; --j) {
      for (int i = 0; i < n; ++i) {
        sum[i][j - 1] += sum[i][j];
        sum[p[i][j - 1]][j - 1] += sum[i][j];
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      if (i) cout << ' ';
      cout << sum[id[i]][0];
    }
    cout << endl;
  }
  return 0;
}
