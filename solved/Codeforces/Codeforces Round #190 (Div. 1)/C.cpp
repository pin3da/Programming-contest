// http://codeforces.com/contest/321/problem/C

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 100001 + 10;
bool removed[MN];
int sz[MN], ans[MN];

void dfs(vector<vector<int>> &g, int node, int pi) {
  sz[node] = 1;
  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i];
    if (to != pi && !removed[to]) {
      dfs(g, to, node);
      sz[node] += sz[to];
    }
  }
}

int find_center(vector<vector<int>> &g, int node) {
  dfs(g, node, -1);
  int cap = sz[node] / 2, pi = -1;
  while (true) {
    bool seen = false;
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i];
      if (!removed[to] && to != pi && sz[to] > cap) {
        seen = true;
        pi = node;
        node = to;
        break;
      }
    }
    if (!seen)
      return node;
  }
}

void magic(vector<vector<int>> &g, int node, int depth) {
  int center = find_center(g, node);
  // D(center);
  ans[center] = depth;
  removed[center] = true;
  for (int i = 0; i < g[center].size(); ++i) {
    int to = g[center][i];
    if (!removed[to])
      magic(g, to, depth + 1);
  }
}

void solve(int n) {
  vector<vector<int>> g(n);
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(removed, 0, sizeof removed);
  magic(g, 0, 0);
  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    cout << char(ans[i] + 'A');
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
