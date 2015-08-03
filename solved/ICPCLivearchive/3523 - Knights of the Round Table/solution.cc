using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 1 << 10;
bool g[MN][MN];
int pre[MN], low[MN], st[MN];
vector<int> bcc[MN];
int color[MN];
bool flag,ok[MN];
int n, ts, sp, cur_bcc;

void dfs(int node) {
  st[sp++] = node;
  pre[node] = low[node] = ts++;
  for (int i = 0; i < n; ++i) {
    if (g[node][i]) {
      if (pre[i] == -1) {
        dfs(i);
        low[node] = min(low[i], low[node]);
        if (low[i] >= pre[node]) {
          int k = 0;
          st[sp] = -1;
          bcc[cur_bcc].clear();
          bcc[cur_bcc].push_back(node);
          while (st[sp] != i) {
            bcc[cur_bcc].push_back(st[--sp]);
          }
          if (bcc[cur_bcc].size() > 1)
            cur_bcc++;
        }
      } else if (pre[i] < low[node])
        low[node]=pre[i];
    }
  }
}

void dfs(int pnt, int c, int col) {
  if(flag)
    return;
  for (int i=0; i<n; ++i) {
    if (g[c][i] && color[i] != 0 && i != pnt && i != c) {
      if(color[i]==1) {
        color[i] = col;
        dfs(c, i, -col);
      } else if (color[i] == color[c]) {
        flag = true;
        return;
      }
    }
  }
}

void slove(int c) {
  for (int i = 0; i < bcc[c].size(); ++i) {
    color[bcc[c][i]] = 1;
  }
  flag = false;
  color[bcc[c][0]] = 2;
  dfs(-1, bcc[c][0], -2);
  for (int i = 0; i < bcc[c].size(); ++i) {
    color[bcc[c][i]] = 0;
    if (flag)
      ok[bcc[c][i]] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;
  while (cin >> n >> m && (n + m)) {
    memset(g, true, sizeof(g));
    memset(pre, -1, sizeof(pre));
    memset(st, 0, sizeof(st));
    memset(color, 0, sizeof(color));
    memset(bcc, 0, sizeof(bcc));
    memset(ok, false, sizeof(ok));
    ts = sp = cur_bcc = 0;
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u--;v--;
      g[u][v]=0;
      g[v][u]=0;
    }
    for (int i = 0; i < n; ++i)
      if (pre[i] == -1)
        dfs(i);

    for (int i = 0; i < cur_bcc; ++i)
      slove(i);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!ok[i])
        ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
