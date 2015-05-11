using namespace std;
#include <bits/stdc++.h>

const int MN = 10001;
struct edge{
  int u, v, w;
  bool operator < (const edge &e ) const {
    return w < e.w;
  }
};

int p[MN];

int fs(int x) {
  return (x == p[x]) ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  p[fs(x)] = fs(y);
}

void solve() {
  int n, m, a;
  cin >> n >> m >> a;
  for (int i = 0; i < n; ++i)
    p[i] = i;

  vector<edge> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w;
    e[i].u--;
    e[i].v--;
  }

  sort(e.begin(), e.end());
  int cost = 0;
  for (int i = 0; i < m; ++i) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    if (w >= a)
      break;
    if (fs(u) == fs(v))
      continue;
    js(u, v);
    cost += w;
  }

  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (fs(i) == i)
      len++;
  }
  printf("%d %d\n", cost + a * len, len);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
