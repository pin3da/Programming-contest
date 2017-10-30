#include <bits/stdc++.h>

using namespace std;

struct edge {
  int to;
  long long cost;
  edge() {}
  edge(int a, long long b) : to(a), cost(b) {}
};

typedef vector<vector<edge>> graph;

pair<long long, long long> dfs(graph &g, vector<int> &cost, int cap, int node, int p) {
  long long cur_cost = 0, cur_total = cost[node];
  for (int i = 0; i < g[node].size(); i++) {
    int to = g[node][i].to;
    if (to == p) continue;
    auto next = dfs(g, cost, cap, to, node);
    cur_cost += next.first;
    cur_cost += g[node][i].cost * ((next.second + cap - 1) / cap);
    cur_total += next.second;
  }
  // cout << "node " << node << " " << cur_total << endl;
  return {cur_cost, cur_total};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, cap;
  cin >> n >> cap;
  vector<int> cost(n);
  for (auto &i : cost) cin >> i;
  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }

  cout << (dfs(g, cost, cap, 0, 0).first << 1) << endl;
  return 0;
}
