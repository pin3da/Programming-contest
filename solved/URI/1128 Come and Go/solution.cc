#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge{
  int from, to, w;
  edge() {}
  edge(int a, int b, int c) : from(a), to(b), w(c) {}
};

typedef  vector<vector<edge>> graph;

void dfs(graph &g, vector<int> &vi, int node) {
  if (vi[node]) return;
  vi[node] = true;
  for (auto &e : g[node])
    dfs(g, vi, e.to);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    vector<vector<edge>> g(n);
    edge e;
    for (int i = 0; i < m; ++i) {
      cin >> e.from >> e.to >> e.w;
      e.from--;e.to--;
      g[e.from].push_back(e);
      if (e.w == 2)
        g[e.to].push_back(edge(e.to, e.from, e.w));
    }

    int ok = true;
    for (int i = 0; i < n && ok; ++i) {
      vector<int> vi(n);
      dfs(g, vi, i);
      if (accumulate(vi.begin(), vi.end(), 0) != n)
        ok = false;
    }
    cout << ok << endl;
  }
  return 0;
}

