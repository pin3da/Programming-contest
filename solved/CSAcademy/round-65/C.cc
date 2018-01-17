#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

void dfs(graph &g, vector<int> &dist, int node, int pi, int depth) {
  dist[node] = depth;
  for (auto to : g[node]) {
    if (to == pi) continue;
    dfs(g, dist, to, node, depth + 1);
  }
}

void child(graph &g, vector<int> &ch, int node, int pi, int end) {
  if (node == end)
    ch[node] = true;

  for (auto to : g[node]) {
    if (pi == to) continue;
    child(g, ch, to, node, end);
    ch[node] |= ch[to];
  }

  int len = g[node].size();
  for (int i = 0; i < len; i++) {
    int to = g[node][i];
    if (ch[to]) {
      swap(g[node][i], g[node][len - 1]);
      break;
    }
  }
}

void solve(graph &g, deque<int> &ans, vector<int> &ch, int node, int pi) {

  ans.push_back(node);
  int len = g[node].size();
  for (int i = 0; i < len; i++) {
    int to = g[node][i];
    if (pi == to) continue;
    solve(g, ans, ch, to, node);
    if (!ch[to])
      ans.push_back(node);
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  graph g(n);
  set<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    edges.insert({min(u, v), max(u, v)});
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dist(n);
  dfs(g, dist, 0, 0, 0);
  int start = 0;
  for (int i = 0; i < n; i++)
    if (dist[i] > dist[start]) start = i;

  fill(dist.begin(), dist.end(), 0);

  dfs(g, dist, start, start, 0);
  int max_len = *max_element(dist.begin(), dist.end());
  int end = 0;
  for (int i = 0; i < n; i++)
    if (dist[i] > dist[end]) end = i;

  vector<int> ch(n);
  child(g, ch, start, start, end);

  deque<int> ans;
  solve(g, ans, ch, start, start);

  assert(int(ans.size()) - 1 == (2 * n - 2 - max_len));

  cout << ans.size() - 1 << endl;
  for (auto it : ans)
    cout << (it + 1) << " ";
  cout << endl;

  for (int i = 1; i < int(ans.size()); i++) {
    int u = ans[i - 1], v = ans[i];
    assert(edges.count({min(u, v), max(u, v)}));
  }
  return 0;
}
