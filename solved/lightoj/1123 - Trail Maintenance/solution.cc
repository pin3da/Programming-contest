using namespace std;
#include <bits/stdc++.h>

struct edge {
  int u, v, w;
  edge() {}
  edge(int a, int b, int c) :
    u(a), v(b), w(c) {}
};

int find_path(vector<set<int> > &g, vector<edge> &e, vector<bool> &vi,
              int cur, int tar, int &w_val, int &w_ind) {

  if (vi[cur]) return false;
  vi[cur] = true;
  if (cur == tar) return true;
  for (set<int>::iterator it = g[cur].begin(); it != g[cur].end(); ++it) {
    int u = e[*it].u, v = e[*it].v;
    if (v == cur) swap(u, v);
    if (find_path(g, e, vi, v, tar, w_val, w_ind)) {
      if (w_val <  e[*it].w) {
        w_val = e[*it].w;
        w_ind = *it;
      }
      return true;
    }
  }

  return false;
}

void dfs(vector<set<int> > &g, vector<edge> &e, vector<bool> &vi, int node) {
  if (vi[node]) return;
  vi[node] = true;
  for (set<int>::iterator it = g[node].begin(); it != g[node].end(); ++it) {
    int u = e[*it].u, v = e[*it].v;
    if (v == node) swap(u, v);
    dfs(g, e, vi, v);
  }
}

void solve() {
  int n, we;
  cin >> n >> we;
  vector<set<int> > g(n);
  vector<edge> edges(we);
  int u, v, w;

  int cost = 0;
  for (int i = 0; i < we; ++i) {
    cin >> u >> v >> w;
    u--;v--;
    edges[i] = edge(u, v, w);
    vector<bool> vi(n);
    int w_val = -1, w_ind = -1;
    if(!find_path(g, edges, vi, u, v, w_val, w_ind)) {
      g[u].insert(i);
      g[v].insert(i);
      cost += w;
    } else if (w_val > w) {
      int up = edges[w_ind].u,
          vp = edges[w_ind].v,
          wp = edges[w_ind].w;

      g[up].erase(w_ind);
      g[vp].erase(w_ind);
      cost += (w - wp);
      g[u].insert(i);
      g[v].insert(i);
    }

    fill(vi.begin(), vi.end(), false);
    dfs(g, edges, vi, 0);
    if (accumulate(vi.begin(), vi.end(), 0) == n)
      printf("%d\n", cost);
    else
      puts("-1");
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
