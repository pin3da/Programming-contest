#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void dfs(vector<vector<int>> &graph, vector<bool> &seen, int root) {
    seen[root] = true;
    for (auto to : graph[root]) {
      if (seen[to]) {
        return;
      }
      dfs(graph, seen, to);
    }
  }

  int findRoot(vector<int> &incoming) {
    int root = 0;
    for (int i = 0; i < incoming.size(); i++) {
      if (incoming[i] == 0)
        root = i;
    }
    return root;
  }

  bool connected(vector<vector<int>> &graph, int root) {
    vector<bool> seen(graph.size());
    dfs(graph, seen, root);
    for (auto it : seen)
      if (!it) return false;
    return true;
  }

  public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int total_nodes = edges.size();

    vector<int> answer;

    for (int exclude = 0; exclude < edges.size(); exclude++) {
      vector<vector<int>> graph(total_nodes);
      vector<int> incoming(total_nodes);
      for (int i = 0; i < edges.size(); i++) {
        if (i == exclude) continue;

        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        graph[u].push_back(v);
        incoming[v]++;
      }
      int root = findRoot(incoming);
      if (connected(graph, root)) {
        answer = edges[exclude];
      }
    }

    return answer;
  }
};
