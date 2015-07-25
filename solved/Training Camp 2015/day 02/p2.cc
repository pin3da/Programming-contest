using namespace std;
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;
typedef VVT Matrix;

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
        if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    if (fabs(a[pj][pk]) < EPS) { cerr << "Matrix is singular." << endl; exit(0); }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    T c = 1.0 / a[pk][pk];
    det *= a[pk][pk];
    a[pk][pk] = 1.0;
    for (int p = 0; p < n; p++) a[pk][p] *= c;
    for (int p = 0; p < m; p++) b[pk][p] *= c;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}


const int MN = 55;

void solve(int n, int k) {
  vector<double> p(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> p[i];
  }


  Matrix A(n, VT(n, 0));
  Matrix B(n, VT(1, 0));
  B[n - 1][0] = 1;
  A[n - 1][n - 1] = 1;

  for (int i = 0; i < n - 1; ++i) {
    A[i][i] = 1;
    int r = (i + 1) % n;
    int l = (i - 1 + n) % n;
    A[i][r] = -p[i];
    A[i][l] = -(1 - p[i]);
  }

  GaussJordan(A, B);
  printf("%.17lf\n", B[k - 1][0]);

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    solve(n, k);
  }
  return 0;
}

