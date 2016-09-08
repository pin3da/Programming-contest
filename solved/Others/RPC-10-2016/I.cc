#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN  = 4;
const int mod = 10;

int add(int x, int y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

struct matrix {
  int r, c;
  int m[MN][MN];

  matrix (int _r, int _c) : r (_r), c (_c) {
    memset(m, 0, sizeof m);
  }

  void print() {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        cout << m[i][j] << " ";
      cout << endl;
    }
  }

  int x[MN][MN];
  matrix & operator *= (const matrix &o) {
    memset(x, 0, sizeof x);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
        if (m[i][k] != 0)
          for (int j = 0; j < c; ++j) {
            x[i][j] = add(x[i][j], ((m[i][k] * o.m[k][j]) % mod) );
          }
    memcpy(m, x, sizeof(m));
    return *this;
  }
};

void matrix_pow(matrix b, long long e, matrix &res) {
  memset(res.m, 0, sizeof res.m);
  for (int i = 0; i < b.r; ++i)
    res.m[i][i] = 1;

  assert(e >= 0);
  if (e == 0) return;
  while (true) {
    if (e & 1) res *= b;
    if ((e >>= 1) == 0) break;
    b *= b;
  }
}

int main() {
  matrix b(4, 4);
  for (int i = 0; i < 4; ++i) b.m[0][i] = 1;
  b.m[1][0] = 0;
  b.m[1][1] = 4;
  b.m[1][2] = mod -3;
  b.m[1][3] = mod -3;
  b.m[2][0] = 0;
  b.m[2][1] = 5;
  b.m[2][2] = mod - 4;
  b.m[2][3] = mod - 4;
  b.m[3][0] = 0;
  b.m[3][1] = mod -1;
  b.m[3][2] = 1;
  b.m[3][3] = 0;

  matrix ans(4, 4);
  int tc; scanf("%d", &tc);
  while (tc--) {
    long long n;
    int a, B, c;
    scanf("%lld %d %d %d", &n, &a, &B, &c);

    matrix_pow(b, n % 15, ans);
    int a1 = add((4 * a - 3 * B - 3 * c) % 10, mod);
    int b1 = add((5 * a - 4 * B - 4 * c) % 10, mod);
    int c1 = add((B - a) % 10 , mod);
    int cur = add((ans.m[0][1] * a1) % mod, (ans.m[0][2] * b1) % mod);
    cur = add(cur, (ans.m[0][3] * c1) % mod);

    cur = add(cur % mod, mod) ;
    printf("%d\n", cur);
  }
  return 0;
}
