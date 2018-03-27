#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < int(w[i].size()); j++) {
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
  for (int i = 0; i < int(w.size()); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  VVI g(n, VI(m));
  VI r, l;
  for (int i = 0; i < q; i++) {
    int u, v; cin >> u >> v; u--;v--;
    g[u][v] = 1;
  }

  VVI g2 = g;

  int match = BipartiteMatching(g, r, l);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) g2[i][j] = 0;
    if (BipartiteMatching(g2, l, r) < match) cout << "N";
    else cout << "P";
    for (int j = 0; j < m; j++) g2[i][j] = g[i][j];
  }

  cout << endl;

  for (int i = 0; i < m; i++) {
    VVI g2 = g;
    for (int j = 0; j < n; j++) g2[j][i] = 0;
    if (BipartiteMatching(g2, l, r) < match) cout << "N";
    else cout << "P";
    for (int j = 0; j < n; j++) g2[j][i] = g[j][i];
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

