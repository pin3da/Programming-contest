using namespace std;
#include <bits/stdc++.h>

typedef unsigned long long ull;


const int MN  = 2;
struct matrix {
  int r, c;
  ull m[MN][MN];

  matrix (int _r, int _c) : r (_r), c (_c) {
    memset(m, 0, sizeof m);
  }

  ull x[MN][MN];
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

  while (e > 0) {
    if (e & 1)
      res *= b;
    b *= b;
    e >>= 1;
  }
}

void solve() {
  ull p, q, n;
  scanf("%llu%llu%llu", &p, &q, &n);
  if (n == 0) {
    printf("2\n");
    return;
  }
  matrix m(2, 2);
  m.m[0][0] = p;
  m.m[0][1] = -q;
  m.m[1][0] = 1;
  m.m[1][1] = 0;

  matrix ans(2, 2);
  matrix_pow(m, n - 1, ans);

  printf("%llu\n", ans.m[0][0] * p + ans.m[0][1] * 2);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
