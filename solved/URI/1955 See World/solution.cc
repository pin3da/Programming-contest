#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool dfs(vector<vector<int>> &g, vector<int> &col, int node, int c) {
  if (col[node] != -1)
    return col[node] == c;
  col[node] = c;
  for (int i = 0; i < g.size(); ++i) {
    if (g[node][i] == 0)
      if (!dfs(g, col, i, c ^ 1))
        return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int> (n));
  for (auto &i : g)
    for (auto &j : i)
      cin >> j;

  vector<int> col(n, -1);
  for (int i = 0; i < n; ++i) {
    if (col[i] == -1)
      if (!dfs(g, col, i, 0)) {
        cout << "Fail!" << endl;
        return 0;
      }
  }

  cout << "Bazinga!" << endl;
  return 0;
}
