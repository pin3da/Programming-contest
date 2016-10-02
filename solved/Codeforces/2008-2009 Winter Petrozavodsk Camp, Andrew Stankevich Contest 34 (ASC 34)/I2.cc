#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int maxn = 100000;
const int inf = 1000000000;

int n, answer, f[maxn][3];
vector<int> adj[maxn];

inline int dfs(int u, int fa)
{
  int cnt = 0;
  f[u][0] = 1;
  f[u][1] = inf;
  f[u][2] = inf;
  for (int i = 0; i < adj[u].size(); ++ i) {
    int v = adj[u][i];
    if (v == fa) {
      continue;
    }
    dfs(v, u);
    int g[3] = {inf, inf, inf};
    for (int j = 2; j >= 0; -- j) {
      g[j] = min(g[j], f[u][j] + f[v][0]);
      if (j + 1 < 3) {
        g[j + 1] = min(g[j + 1], f[u][j] + f[v][1]);
      }
    }
    memcpy(f[u], g, sizeof(g));
  }
  int g[3];
  memcpy(g, f[u], sizeof(g));
  f[u][0] = min(min(g[0], g[1] - 1), g[2] - 2);
  f[u][1] = min(g[0], g[1] - 1);
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i < n; ++ i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);
  printf("%d\n", f[0][0]);
  return 0;
}

