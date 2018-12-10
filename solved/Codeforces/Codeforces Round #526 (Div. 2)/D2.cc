#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Node {
  struct Edge {
    Node* to;
    long long cost;
  };
  long long w, best, path;
  vector<Edge> children;
};

void dfs(Node* node, Node* pi) {
  node->best = node->w;
  node->path = node->w;

  vector<long long> tmp;
  for (auto edge : node->children) {
    if (edge.to == pi) continue;
    dfs(edge.to, node);
    long long option = edge.to->path - edge.cost;
    if (option > 0)
      tmp.emplace_back(option);
  }

  sort(tmp.rbegin(), tmp.rend());
  if (tmp.size() >= 1) {
    node->path = max(node->path, node->path + tmp[0]);
    node->best = max(node->best, node->path);
  }
  if (tmp.size() > 1) {
    long long opt = node->w + tmp[0] + tmp[1];
    if (opt > node->best) {
      node->best = opt;
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
    nodes[u].children.push_back({&nodes[v], len});
    nodes[v].children.push_back({&nodes[u], len});
  }

  dfs(&nodes[0], nullptr);

  long long best = 0;
  for (auto it : nodes) {
    best = max(best, it.best);
  }
  cout << best << endl;
  return 0;
}
