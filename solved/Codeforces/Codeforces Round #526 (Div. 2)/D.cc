#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Edge {
  int to;
  long long cost;
};

struct Node {
  long long w, best, path;
  vector<Edge> children;
};

void dfs(vector<Node> &nodes, int id, int pi) {
  nodes[id].best = nodes[id].w;
  nodes[id].path = nodes[id].w;

  vector<long long> tmp;
  for (auto edge : nodes[id].children) {
    if (edge.to == pi) continue;
    dfs(nodes, edge.to, id);
    long long option = nodes[edge.to].path - edge.cost;
    if (option > 0)
      tmp.emplace_back(option);
  }

  sort(tmp.rbegin(), tmp.rend());
  if (tmp.size() >= 1) {
    nodes[id].path = max(nodes[id].path, nodes[id].path + tmp[0]);
    nodes[id].best = max(nodes[id].best, nodes[id].path);
  }
  if (tmp.size() > 1) {
    long long opt = nodes[id].w + tmp[0] + tmp[1];
    if (opt > nodes[id].best) {
      nodes[id].best = opt;
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif
  int n;
  cin >> n;
  vector<Node> nodes(n);

  for (int i = 0; i < n; i++) {
    cin >> nodes[i].w;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v, len;
    cin >> u >> v >> len;
    u--; v--;
    nodes[u].children.push_back({v, len});
    nodes[v].children.push_back({u, len});
  }

  dfs(nodes, 0, -1);

  long long best = 0;
  for (auto it : nodes) {
    best = max(best, it.best);
  }
  cout << best << endl;
  return 0;
}
