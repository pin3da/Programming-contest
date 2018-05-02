#include "./solution.cc"

int main() {

  Solution sol;

  vector<vector<int>> edges;
  edges.push_back({2, 1});
  edges.push_back({3, 1});
  edges.push_back({4, 2});
  edges.push_back({1, 4});

  auto ans = sol.findRedundantDirectedConnection(edges);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
