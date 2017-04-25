// http://codeforces.com/contest/707/problem/B

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

struct edge {
  int to, w;
  edge(int a, int b) : to(a), w(b) {}
  edge() {}
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<vector<edge> > g(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      u--;v--;
      g[u].push_back(edge(v, w));
      g[v].push_back(edge(u, w));
    }
    vector<int> sup(k);
    set<int> s;
    for (int i = 0; i < k; ++i) {
      cin >> sup[i];
      sup[i]--;
      s.insert(sup[i]);
    }

    int inf = 1000000000 + 100;
    int best = inf;
    for (int i = 0; i < k; ++i) {
      int u = sup[i];
      for (int j = 0; j < g[u].size(); ++j) {
        int to = g[u][j].to;
        int w = g[u][j].w;
        if (s.count(to) == 0) best = min(best, w);
      }
    }
    if (best == inf) {
      cout << -1 << endl;
    } else {
      cout << best << endl;
    }
  }

  return 0;
}
