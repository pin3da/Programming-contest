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

int n, m;
void solve() {
  VVI g(n, VI(n, 0));
  VI L, R;
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    g[u][v] = 1;
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        g[i][j] |= g[i][k] && g[k][j];

  cout << n - BipartiteMatching(g, L, R) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> n >> m && (n + m)) {
    solve();
  }
  return 0;
}
