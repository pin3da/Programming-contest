#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

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


int c, d;

void gen_states(set<pair<int, int>> &s, int a, int b) {
  if (b <= 0)
    s.insert(make_pair(a, 0));
  else if (a <= 0)
    s.insert(make_pair(0, b));
  else if (s.count(make_pair(a, b)))
    return;
  else {
    s.insert(make_pair(a, b));
    gen_states(s, a + d, b - d);
    gen_states(s, a - d, b + d);
  }


}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cout << fixed << setprecision(1);
  int a, b;
  while (cin >> a >> b >> c >> d && (a + b + c + d)) {
    set<pair<int, int>> s;
    gen_states(s, a, b);
    VVT A(s.size(), VT(s.size(), 0));
    VVT B(s.size(), VT(1, 0));
    for (int i = 1; i < s.size() - 1; ++i) {
      A[i][i - 1] = 1.0 - (c / 6.0);
      A[i][i] = -1;
      A[i][i + 1] = (c / 6.0);
    }
    A[0][0] = 1;
    A[s.size() - 1][s.size() - 1] = 1;
    B[s.size() - 1][0] = 1;
    GaussJordan(A, B);
    int idx = distance(s.begin(), s.find(make_pair(a, b)));
    cout << B[idx][0] * 100 << endl;
  }
  return 0;
}
