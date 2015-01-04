using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

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
  cin >> n >> m;
  vector<vector<int> > w(n, vector<int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char t;
      cin >> t;
      w[i][j] = (t == '1');
    }
  }

  vector<int> mr, mc;
  cout << BipartiteMatching(w, mr, mc) << endl;



}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
