#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;

struct Node {
  void AddTo(Node *to) {
    adj.push_back(to);
    num_edges++;
  }

  vector<Node *> UnprocessedNeighbors() {
    vector<Node *> ans;
    for (auto to : adj) {
      if (!to->queued) ans.push_back(to);
    }
    return ans;
  }

  int id;
  int timestamp;
  bool queued;
  int num_edges;
  vector<Node *> adj;
};

struct Graph {
  Graph(int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
      nodes.push_back(
          Node{.id = i, .timestamp = 1, .queued = false, .num_edges = 0});
    }
  }

  void AddEdge(int a, int b) {
    nodes[a].AddTo(&nodes[b]);
    nodes[b].AddTo(&nodes[a]);
  }

  void MarkLeaves() {
    for (auto &node : nodes) {
      if (node.num_edges == 1) {
        unprocessed_leaves.push_back(&node);
        node.queued = true;
      }
    }
  }

  vector<Node> nodes;
  deque<Node *> unprocessed_leaves;
};

void solve() {
  int n, k;
  cin >> n >> k;
  Graph g(n);
  for (int i = 0; i < (n - 1); i++) {
    int a, b;
    cin >> a >> b;
    g.AddEdge(a - 1, b - 1);
  }
  g.MarkLeaves();
  while (g.unprocessed_leaves.size() > 0) {
    Node *leave = g.unprocessed_leaves.front();
    g.unprocessed_leaves.pop_front();
    for (auto *to : leave->UnprocessedNeighbors()) {
      to->timestamp = max(to->timestamp, leave->timestamp + 1);
      to->num_edges--;
      if (to->num_edges == 1) {
        g.unprocessed_leaves.push_back(to);
        to->queued = true;
      }
    }
    leave->queued = true;
  }
  int ans = 0;
  for (auto &node : g.nodes) {
    if (node.timestamp > k) ans++;
  }
  cout << ans << endl;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}