#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct edge {
  int v, w;
  edge(int a) : v(a), w(0) {}
};

typedef vector<vector<edge>> graph;

const int MN = 1e6;
const int ML = 21;

int color[MN];

struct lowest_ca {
  int T[MN], L[MN];
  int P[MN][ML];

  void dfs(vector<vector<edge> > &g, int root, int pi = -1) {
    if (pi == -1) {
      L[root] = 0;
      T[root] = -1;
    }
    for (int i = 0; i < (int)g[root].size(); ++i) {
      int to = g[root][i].v;
      if (to != pi) {
        T[to] = root;
        L[to] = L[root] + 1;
        dfs(g, to, root);
      }
    }
  }

  void init(vector<vector<edge> > &g, int root) {
    // g is undirected
    dfs(g, root);
    int N = g.size(), i, j;

    for (i = 0; i < N; i++) {
      for (j = 0; 1 << j < N; j++) {
        P[i][j] = -1;
      }
    }

    for (i = 0; i < N; i++) {
      P[i][0] = T[i];
    }

    for (j = 1; 1 << j < N; j++)
      for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1) {
          P[i][j] = P[P[i][j - 1]][j - 1];
        }
  }

  int get_uncolored(int cur) {
    int dist = L[cur];
    int ans = 1;
    for (int i = ML - 1; i >= 0; i--) {
      int step = 1 << i;
      if (step <= dist && (color[P[cur][i]] == -1)) {
        ans += step;
        cur = P[cur][i];
        dist -= step;
      }
    }
    return ans;
  }

  void paint_path(int cur) {
    while (color[cur] == -1) {
      color[cur] = 0;
      cur = P[cur][0];
    }
  }
};


lowest_ca lca;

void solve() {
  int n, k;
  cin >> n >> k;
  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--;v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  lca.init(g, n - 1);

  for (int i = 0; i < n; i++) {
    color[i] = -1;
  }
  color[n - 1] = 0;

  int total = n - k;
  int current = 1;

  vector<int> ans;
  for (int i = n - 2; i >= 0; i--) {
    int extra = lca.get_uncolored(i);
    if ((color[i] == -1) && (current + extra <= total)) {
      lca.paint_path(i);
      current += extra;
    } else {
      if (color[i] == -1)
        ans.emplace_back(i + 1);
    }
  }

  reverse(ans.begin(), ans.end());
  for (int i = 0; i < int(ans.size()); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

