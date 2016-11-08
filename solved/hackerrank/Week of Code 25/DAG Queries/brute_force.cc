#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 1e5 + 100;
vector<int> g[MN];
int color[MN];
int val[MN];
int curcol;

void dfs(int node, int x, int t) {

  if (color[node] == curcol) return;
  color[node] = curcol;

  if (t == 1) val[node] = x;
  else val[node] = min(x, val[node]);

  for (int i = 0; i < (int)g[node].size(); ++i)
    dfs(g[node][i], x, t);
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  curcol = 1;
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }

  for (int i = 0; i < q; ++i) {
    int t, u, x;
    cin >> t >> u;
    if (t < 3) {
      cin >> x;
      dfs(u - 1, x, t);
      curcol++;
    } else {
      cout << val[u - 1] << endl;
    }
  }

  return 0;
}
