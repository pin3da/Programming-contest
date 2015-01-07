using namespace std;
#include <bits/stdc++.h>

typedef long double ld;

const ld inf = 1e100;

struct edge {
  int to;
  ld p;
  edge() {}
  edge(int a, ld b) : to(a), p(b) {}
  bool operator < (const edge &o) const {
    return p < o.p;
  }
};

void solve() {
  int n, m, s, k;
  cin >> n >> m >> s >> k;
  int u, v, p;
  vector<vector<edge> > g(n);
  vector<vector<long double> > prob(n, vector<long double>(n, 0));
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> p;
    prob[u][v] = prob[v][u] = p / 100.0;
  }

  for (int i = 0; i < n; ++i)
    prob[i][i] = 1.0;

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        prob[i][j] =  max(prob[i][j], prob[i][k] * prob[k][j]);

  double ans = prob[0][n - 1];


  // cout << ans << endl;
  double exp = (1.0 / ans ) * (2.0 * s * k);
  printf("%.10lf\n", exp + 1e-9);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
