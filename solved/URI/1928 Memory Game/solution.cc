#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef vector<vector<int>> graph;

const int MAXN = 100001;

int tin[MAXN], tout[MAXN];
int dist[MAXN];

vector<int> up[MAXN];
vector<int> g[MAXN];
// alternatively, you can use a global graph to save space.
// This graph is only used inside LCA::dfs below.

int L, timer;

void clear(int n) {
  for (int i = 0; i < n; ++i) g[i].clear();
}
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= L; ++i)
    up[v][i] = up[up[v][i-1]][i-1];
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to != p) {
      dist[to] = dist[v] + 1;
      dfs(to, v);
    }
  }
  tout[v] = ++timer;
}
inline bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = L; i >= 0; --i)
    if (!upper(up[a][i], b))
      a = up[a][i];
  return up[a][0];
}

void preprocess(int n, int root) {
  L = 1;
  while ((1 << L) <= n) ++L;
  for (int i = 0; i < n; ++i) up[i].resize(L + 1);
  timer = 0;
  dfs(root, root);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, t;
  cin >> n;
  vector<vector<int>> a(n / 2);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    t--;
    a[t].emplace_back(i);
  }

  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    add_edge(u - 1, v - 1);
  }

  preprocess(n, 0);


  long long ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    u = a[i][0], v = a[i][1];
    int c = lca(u, v);
    ans += dist[u] + dist[v] - 2 * dist[c];
  }
  cout << ans << endl;

  return 0;
}
