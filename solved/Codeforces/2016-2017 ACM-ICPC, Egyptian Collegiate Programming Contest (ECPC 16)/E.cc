#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1e5 + 100;
int d[MN];
int dist[MN];
int q[MN];
vector<int> g[MN];

void bfs(int s, int n) {
  for (int i = 0; i < n; ++i)
    dist[i] = n * n;

  dist[s] = 0;
  int head = 0, tail = 0;
  q[head++] = s;
  while (head > tail) {
    int cur = q[tail++];
    for (int i = 0; i < (int)g[cur].size(); ++i) {
      int to = g[cur][i];
      int w = dist[cur] + 1;
      if (to >= 0 && to < n && w < dist[to]) {
        dist[to] = w;
        q[head++] = to;
      }
    }
  }
}

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    scanf("%d", d + i);
  }

  for (int i = 0; i < n; ++i) {
    int to = i + d[i];
    if (to < n)
      g[to].push_back(i);
    to = i - d[i];
    if (to >= 0)
      g[to].push_back(i);
  }

  bfs(n - 1, n);
  for (int i = 0; i < n; ++i) {
    if (dist[i] <= n) printf("%d\n", dist[i]);
    else puts("-1");
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  freopen("jumping.in", "r", stdin);
#endif

  int t; scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
