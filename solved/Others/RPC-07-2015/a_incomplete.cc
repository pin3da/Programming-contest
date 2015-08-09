using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 1010;
int p[MN];

int fs(int x) {
  return (x == p[x]) ? x : p[x] = fs(p[x]);
}

set<int> used;
int dfs(vector<vector<int>> &g, int node, int pi) {
  for (int i = 0; i < g[node].size(); ++i) if (g[node][i] != pi) {
    dfs(g, g[node][i], node);
  }

  if (used.count(node) == 0 && used.count(pi) == 0) {
    used.insert(node);
    if (pi != -1)
      used.insert(pi);
  }
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int u, v, w;
  vector<int> die(n, 0);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u--;v--;
    if (w == 0)
      die[u] = die[v] = 1;
    if (w == 2) {
      if (die[u] == 1 || die[v] == 1) {
        cout << "impossible" << endl;
        return 0;
      }
      die[u] = die[v] = 2;
    }
    if (w == 1) {
      edges.push_back(make_pair(u, v));
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (die[i] == 2)
      ans++;

    p[i] = i;
  }


  vector<vector<int>> g(n);
  int root = -1;
  for (int i = 0; i < edges.size(); ++i) {
    int u = edges[i].first, v = edges[i].second;
    if (!die[u] && !die[v]) {
      if (fs(u) == fs(v)) {
        cout << "impossible" << endl;
        return 0;
      }
      p[fs(u)] = fs(v);
      g[u].push_back(v);
      g[v].push_back(u);
      root = u;
    }
  }

  if (root < 0) {
    cout << ans << endl;
  } else {
    used.clear();
    dfs(g, root, -1);

    cout << ans + (used.size()  + 1)/ 2 << endl;
  }

  return 0;
}
