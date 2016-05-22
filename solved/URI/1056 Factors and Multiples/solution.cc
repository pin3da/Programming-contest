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
  cin >> n;
  vector<int> right(n);
  for (int i = 0; i < n; ++i)
    cin >> right[i];

  cin >> m;
  vector<int> left(m);
  for (int i = 0; i < m; ++i)
    cin >> left[i];

  VVI graph(n, VI(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (right[i] == 0) {
        if (left[j] == 0)
          graph[i][j] = 1;
      } else {
        if ((left[j] % right[i]) == 0)
          graph[i][j] = 1;
      }
    }
  }

  printf("%d\n", BipartiteMatching(graph, right, left));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}

