#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef vector<vector<int>> graph;

const int inf = 1000;
int dfs(graph &g, vector<int> &vi, vector<int> &age,
        int node, int col) {

  int ans = inf;
  vi[node] = col;
  for (auto &to : g[node]) {
    if (vi[to] < col)
      ans = min(min(ans, age[to]), dfs(g, vi, age, to, col));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, q;
  while (cin >> n >> m >> q) {
    graph g(n);
    vector<int> age(n);
    vector<int> index(n);
    for (auto &i : age) cin >> i;
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--; v--;
      g[v].emplace_back(u);
    }
    for (int i = 0; i < n; ++i) index[i] = i;
    vector<int> vi(n, -1);
    for (int i = 0; i < q; ++i) {
      char op; cin >> op;
      if (op == 'T') {
        cin >> u >> v;
        u--;v--;
        swap(age[index[u]], age[index[v]]);
        swap(index[u], index[v]);
      } else {
        cin >> u;
        u--;
        if (!g[index[u]].size())
          cout << "*" << endl;
        else {
          cout << dfs(g, vi, age, index[u], i) << endl;
        }
      }
    }
  }

  return 0;
}
