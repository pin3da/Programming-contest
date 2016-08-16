#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

const int MN  = 3;
const long long mod = 1000000000;

struct matrix {
  long long r, c;
  long long m[MN][MN];

  matrix (long long _r, long long _c) : r (_r), c (_c) {
    memset(m, 0, sizeof m);
  }

  void print() {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        cout << m[i][j] << " ";
      cout << endl;
    }
  }

  long long x[MN][MN];
  matrix & operator *= (const matrix &o) {
    memset(x, 0, sizeof x);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
        if (m[i][k] != 0)
          for (int j = 0; j < c; ++j) {
            x[i][j] = (x[i][j] +  ((m[i][k] * o.m[k][j]) % mod) ) % mod;
          }
    memcpy(m, x, sizeof(m));
    return *this;
  }
};

void matrix_pow(matrix b, long long e, matrix &res) {
  memset(res.m, 0, sizeof res.m);
  for (int i = 0; i < b.r; ++i)
    res.m[i][i] = 1;

  if (e == 0) return;
  while (true) {
    if (e & 1) res *= b;
    if ((e >>= 1) == 0) break;
    b *= b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int p; cin >> p;
  while (p--) {
    long long k, y;
    cin >> k >> y;
    cout << k << ' ';
    matrix a(2, 2), ans(2, 2);
    a.m[0][0] = 1;
    a.m[0][1] = 1;
    a.m[1][0] = 1;
    a.m[1][1] = 0;
    matrix_pow(a, y, ans);
    cout << (ans.m[0][1]) % mod << endl;

  }
  return 0;
}
