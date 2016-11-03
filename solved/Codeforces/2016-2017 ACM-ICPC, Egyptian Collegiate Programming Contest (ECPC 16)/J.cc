#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 500000 + 100;
const int ML = 20;
const long long inf = 1LL << 55;

struct edge {
  int to, w;
  edge(int a, int b) : to(a), w(b) {}
  edge() {}
};

long long x[MN];
long long d[MN][ML];
long long ans[MN][ML];
long long tot[MN];
int p[MN][ML];

vector<edge> g[MN];

void dfs(int node, int pi = 0) {
  for (int i = 0; i < (int) g[node].size(); ++i) {
    int to = g[node][i].to;
    int w  = g[node][i].w;
    if (to == pi) continue;
    d[to][0] = w;
    p[to][0] = node;
    dfs(to, node);
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", x + i);
    g[i].clear();
  }

  for (int i = 0; i + 1 < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--;v--;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  memset(ans, 0, sizeof ans);
  memset(tot, 0, sizeof tot);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < ML; ++j) {
      p[i][j] = -1;
      d[i][j] = inf;
    }
  }

  dfs(0);

  for (int k = 1; k < ML; ++k) {
    for (int i = 0; i < n; ++i) {
      if (p[i][k - 1] != -1) {
        d[i][k] = d[i][k - 1] + d[p[i][k - 1]][k - 1];
        p[i][k] = p[p[i][k - 1]][k - 1];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    long long disp = x[i];
    int node = i;
    for (int k = ML - 1; k >= 0; --k) {
      if (p[node][k] != - 1 && disp >= d[node][k]) {
        ans[node][k]++;
        disp -= d[node][k];
        node = p[node][k];
      }
    }
  }

  for (int k = ML - 1; k > 0; --k) {
    for (int i = 0; i < n; ++i) {
      ans[i][k - 1] += ans[i][k];
      ans[p[i][k - 1]][k - 1] += ans[i][k];
    }
  }

  for (int i = 0; i < n; ++i) {
    tot[p[i][0]] += ans[i][0];
  }
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%lld", tot[i]);
  }
  puts("");
}

int main() {
#ifndef LOCAL
  freopen("car.in", "r", stdin);
#endif

  int t; scanf("%d", &t);
  while(t--) solve();

  return 0;
}
