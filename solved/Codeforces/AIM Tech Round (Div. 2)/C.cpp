// http://codeforces.com/contest/624/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 500;
int col[MN];

void dfs(vector<vector<int>> &g, int node, int c) {
  if (col[node] != -1)
    return;

  col[node] = c;
  for (int i = 0; i < g[node].size(); ++i)
    if (g[node][i])
      dfs(g, i, c ^ 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> g(n, vector<int> (n));
    vector<vector<int>> g2(n, vector<int> (n));
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--;v--;
      g[u][v] = 1;
      g[v][u] = 1;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && !g[i][j])
          g2[i][j] = true;
      }
    }

    string ans(n, 'b');
    memset(col, -1, sizeof col);
    int cool = true;
    for (int i = 0; i < n && cool; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        if (g2[i][j]) {
          dfs(g2, i, 0);
          cool = 0;
          break;
        }
      }
    }

    cool = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if(g2[i][j])
          cool &= (col[i] + col[j] == 1);
        else
          cool &= (col[i] + col[j] != 1);
      }
      if (col[i] == 0)
        ans[i] = 'a';
      else if (col[i] == 1)
        ans[i] = 'c';
    }

    if (cool) {
      cout << "Yes" << endl;
      cout << ans << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
