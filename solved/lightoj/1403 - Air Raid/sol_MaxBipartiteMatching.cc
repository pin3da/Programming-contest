using namespace std;
#include <bits/stdc++.h>


typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  int u, v;
  VVI g(n, VI(n));
  VI r(n), l(n);
  for (int i = 0; i < m; ++i) {
  scanf("%d %d", &u, &v);
    u--;v--;
    g[u][v] = 1;
  }
  printf("%d\n", n - BipartiteMatching(g, r, l));

}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
