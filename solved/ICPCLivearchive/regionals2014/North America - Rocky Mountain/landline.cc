using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

struct edge{
  int u, v, w;
  edge() {}
  edge(int a, int b, int c) : u(a), v(b), w(c) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

const int MN = 1000 + 10 + 1;
int pi[MN];

int fs(int x) {
  return pi[x] == x ? x : fs(pi[x]);
}

int js(int x, int y) {
  pi[fs(x)] = fs(y);
}

void check_complete(int n, int m) {
  vector<vector<int> > g(n, vector<int> (n, -1));
  int u, v, w;
  long long total = 0;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u--;v--;
    g[v][u] = g[u][v] = w;
    total += w;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (g[i][j] == -1) {
        cout << "impossible" << endl;
        return;
      }
    }
  }

  cout << total << endl;
}

void solve(int n, int m, int p) {
  vector<edge> edges;
  vector<vector<edge> > bad(n);
  vector<bool> is_bad(n);
  int t;
  for (int i = 0; i < p; ++i) {
    cin >> t;
    is_bad[t - 1] = 1;
  }

  int all_bad = true;
  for (int i = 0; i < n; ++i) {
    all_bad &= is_bad[i];
  }

  if (all_bad) {
    check_complete(n, m);
    return;
  }

  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u--;v--;
    if (!is_bad[u] && !is_bad[v]) {
      edges.push_back(edge(u, v, w));
    } else {
      if (is_bad[u])
        bad[u].push_back(edge(u, v, w));
      if (is_bad[v])
        bad[v].push_back(edge(v, u, w));
    }
  }

  sort(edges.begin(), edges.end());

  for (int i = 0; i < n; ++i)
    pi[i] = i;


  long long total = 0;
  for (int i = 0; i < edges.size(); ++i) {
    if (fs(edges[i].u) == fs(edges[i].v)) continue;
    total += edges[i].w;
    js(edges[i].u, edges[i].v);
  }


  for (int i = 0; i < bad.size(); ++i) {
    if (bad[i].size() == 0) continue;
    sort(bad[i].begin(), bad[i].end());
    for (int j = 0; j < bad[i].size(); ++j) {
      if (!is_bad[bad[i][j].v]) {
        js(i, bad[i][j].v);
        total += bad[i][j].w;
        break;
      }
    }
  }

  unordered_set<int> color;
  for (int i = 0; i < n; ++i) {
    color.insert(fs(i));
  }

  if (color.size() == 1) {
    cout << total << endl;
  } else {
    cout << "impossible" << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, p;
  while (cin >> n >> m >> p) solve(n, m, p);
  return 0;
}
