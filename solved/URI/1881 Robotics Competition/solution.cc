#include<bits/stdc++.h>
using namespace std;

const int MN  = 4;

typedef long double ld;

struct matrix {
  int r, c;
  ld m[MN][MN];

  matrix (int _r, int _c) : r (_r), c (_c) {
    for (int i = 0; i < _r; ++i) {
      for (int j = 0; j < c; ++j)
        m[i][j] = 0;
    }
  }

  void print() {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        cout << m[i][j] << " ";
      cout << endl;
    }
  }

  ld x[MN][MN];
  matrix & operator *= (const matrix &o) {
    memset(x, 0, sizeof x);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
        if (m[i][k] != 0)
          for (int j = 0; j < c; ++j) {
            x[i][j] += m[i][k] * o.m[k][j];
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

const ld pi = acos(-1);

void solve() {
  ld alpha, l;
  int n;
  cin >> alpha >> l >> n;
  alpha = alpha * pi / 180.0;

  if (n == 0) {
    cout << 0 << endl;
    return;
  }

  matrix base(3, 3);
  base.m[0][0] = cos(alpha);
  base.m[0][1] = -sin(alpha);
  base.m[0][2] = 1;
  base.m[1][0] = sin(alpha);
  base.m[1][1] = cos(alpha);
  base.m[1][2] = 0;
  base.m[2][0] = 0;
  base.m[2][1] = 0;
  base.m[2][2] = 1;
  matrix ans(3, 3);
  matrix_pow(base, n - 1, ans);
  // ans.print();
  ld x = l * ans.m[0][0] + l * ans.m[0][2];
  ld y = l * ans.m[1][0] + l * ans.m[1][2];
  cout << x + 1e-9 << " " << y + 1e-9 << endl;
}

int main() {
  int tc; cin >> tc;
  cout << fixed << setprecision(2);
  while (tc--) solve();
  return 0;
}
