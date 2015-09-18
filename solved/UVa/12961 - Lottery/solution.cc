using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const double EPSILON = 1e-10;

typedef int T;
typedef vector<T> VT;
typedef vector<VT> VVT;

int rref(VVT &a) {
  int n = a.size();
  int m = a[0].size();
  int r = 0;
  for (int c = 0; c < m && r < n; c++) {
    int j = r;
    for (int i = r + 1; i < n; i++)
      if (fabs(a[i][c]) > fabs(a[j][c])) j = i;
    if (fabs(a[j][c]) < EPSILON) continue;
    swap(a[j], a[r]);

    for (int i = 0; i < n; i++) if (i != r) {
      if (a[i][c])
        for (int j = 0; j < m; j++) a[i][j] ^=  a[r][j];
    }
    r++;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, t;
  while (cin >> n >> m) {
    VVT a(n, VT(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> t;
        a[i][j] = t & 1;
      }
    }
    int rank = rref(a);
    if (rank < m)
      cout << "S" << endl;
    else {
      if (n > rank) // you can actually gen zeroes.
        cout << "N" << endl;
      else
        cout << "S" << endl;
    }
  }

  return 0;
}
