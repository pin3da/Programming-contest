// ACC at : http://codeforces.com/gym/101047/problem/D
// WA at URI, maybe there is a problem with the test cases

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct edge {
  int to;
  int w;
  edge(int a, int b) : to(a), w(b) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

const long long inf = 1e9 + 100;

const int MN = 1e5 + 100;
vector<edge>  g[MN];
int d[MN];

void dijkstra(int n, int s) {
  for (int i = 0; i < n; ++i)
    d[i] = inf;

  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    int cur  = q.top().to;
    long long dist = q.top().w;
    q.pop();

    if (dist > d[cur]) continue;
    for (int i = 0; i < (int)g[cur].size(); ++i) {
      int to = g[cur][i].to;
      long long w_extra = g[cur][i].w;
      if (dist + w_extra < d[to]) {
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  cout << fixed << setprecision(5);
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < m; ++i) {
      int u, v, w; cin >> u >> v >> w;
      u--;v--;
      g[u].push_back(edge(v, w));
      g[v].push_back(edge(u, w));
    }
    dijkstra(n, n - 1);
    double ini_d = d[0];
    sort(d, d + n);
    reverse(d, d + n);

    long long acc = accumulate(d, d + n, 0LL);
    double ans = 1e100;
    for (int i = 0; i + 1 < n; ++i) {
      acc -= d[i];
      if (d[i] == d[i + 1]) continue;
      int a = i + 1;
      int b = n - a;
      double exp = double(a * k + b * k + acc) / (b);
      ans = min(ans, exp);
    }
    ans = min(ans, ini_d);
    cout << ans + 1e-10 << endl;
  }
  return 0;
}
