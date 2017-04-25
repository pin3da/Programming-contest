// http://codeforces.com/contest/553/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const long long mod = 1000000007;

struct edge{
  int to, type;
};

int col[] = {1, 2};

bool check_bipartite(vector<vector<edge>> &g, vector<int> &c, int node, int pi, int cur) {
  if (c[node] == 0) {
    c[node] = col[cur];
    for (int i = 0; i < g[node].size(); ++i) {
      if (g[node][i].to == pi) continue;
      if (!check_bipartite(g, c, g[node][i].to, node, cur ^ (g[node][i].type))) {
        return false;
      }
    }
    return true;
  } else {
    return c[node] == col[cur];
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<edge>> g(n);
  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back((edge){v, w ^ 1});
    g[v].push_back((edge){u, w ^ 1});
  }

  vector<int> color(n, 0);
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      if (check_bipartite(g, color, i, -1, 0))
        cc++;
      else {
        cout << 0 << endl;
        return 0;
      }
    }
  }

  cc--;
  long long ans = 1, base = 2;
  while (cc > 0) {
    if (cc & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    cc >>= 1;
  }

  cout << ans % mod << endl;
  return 0;
}
