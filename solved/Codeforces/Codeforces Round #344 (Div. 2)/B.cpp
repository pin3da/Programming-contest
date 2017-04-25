// http://codeforces.com/contest/631/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<int> rw(n), tr(n);
    vector<int> cl(m), tc(m);
    int op, ind, col, ti = 1;
    while (k--) {
      cin >> op >> ind >> col;
      ind--;
      if (op == 1) {
        rw[ind] = col;
        tr[ind] = ti;
      } else {
        cl[ind] = col;
        tc[ind] = ti;
      }
      ti++;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j) cout << " ";
        if (tr[i] > tc[j])
          cout << rw[i];
        else
          cout << cl[j];
      }
      cout << endl;
    }
  }
  return 0;
}
