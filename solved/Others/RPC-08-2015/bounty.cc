using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef vector<int> VI;
typedef vector<VI> VVI;


bool find_match(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); ++j) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || find_match(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int mcbm(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  int ct = 0;
  for (int i = 0; i < w.size(); ++i) {
    VI seen(w[0].size());
    if (find_match(i, w, mr, mc, seen))
      ct++;
  }
  
  return ct;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  VVI g(n, VI(n));
  for (int i = 0; i < n; ++i) {
    int c, t; cin >> c;
    for (int j = 0; j < c; ++j) {
      cin >> t;
      g[i][t] = true;
    }
  }
  
  VI L(n), R(n);
  
  cout << n - mcbm(g, L, R) << endl;
  
  return 0;
}
