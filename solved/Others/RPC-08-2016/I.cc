#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int get_id(map<string, int> &id, string a) {
  if (id.count(a)) return id[a];
  int ans = id.size();
  return id[a] = ans;
}

typedef vector<vector<int> > graph;
const int MN = 3333;
int v[MN];
int dist[MN];

int color;

int dfs(graph &g, int node, int depth) {
  dist[node] = 0;
  deque<int> q;
  q.push_back(node);
  v[node] = color;
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    for (int i = 0;i < g[cur].size(); ++i) {
      int to = g[cur][i];
      if (v[to] < color) {
        v[to] = color;
        dist[to] = dist[cur] + 1;
        if (dist[to] > 6) return true;
        q.push_back(to);
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  color = 1;
  while (tc--) {
    int n; cin >> n;
    map<string, int> id;
    graph g(MN);
    for (int i = 0; i < n; ++i) {
      string su, sv; cin >> su >> sv;
      int u = get_id(id, su);
      int v = get_id(id, sv);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int count = 0;
    for (int i = 0; i < id.size(); ++i) {
      if (dfs(g, i, 0))
        count++;
      color++;
    }
    int total = id.size();
    if (count * 20 <= total)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
