using namespace std;
#include <bits/stdc++.h>

struct data {
  int h, a, d;
};

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
  int m, n;
  cin >> m >> n;
  vector<data> men(m), women(n);
  for (int i = 0; i < m; ++i)
    cin >> men[i].h >> men[i].a >> men[i].d;

  for (int i = 0; i < n; ++i)
    cin >> women[i].h >> women[i].a >> women[i].d;

  VVI graph(m, VI(n, 0));
  VI left(m), right(n);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (fabs(men[i].h - women[j].h) <= 12 and fabs(men[i].a - women[j].a) <= 5 and !(men[i].d ^ women[j].d))
        graph[i][j] = 1;

  printf("%d\n", BipartiteMatching(graph, left, right));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
