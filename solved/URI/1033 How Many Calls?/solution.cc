#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN  = 5;
long long mod = 100000;

typedef long long T;
struct matrix {
  int r, c;
  T m[MN][MN];

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

  T x[MN][MN];
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

typedef unsigned long long ull;

void matrix_pow(matrix b, ull e, matrix &res) {
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

void solve(ull n, ull m) {
  ull a = 1, b = 1, c = 1;
  mod = m;
  if (n <= 1) {
    printf("%llu %llu %d\n", n, m, 1 % m);
    return;
  }

  matrix base(3, 3);
  matrix ans(3, 3);
  base.m[0][0] = base.m[0][1] = base.m[0][2] = base.m[1][0] = 1;
  base.m[2][2] = 1;
  matrix_pow(base, n - 1, ans);
  int tmp = ((ans.m[0][0] * b) % mod + (ans.m[0][1] * a) % mod) % mod;
  tmp = (tmp + (ans.m[0][2] * c) % mod) % mod;
  printf("%llu %llu %d\n", n, m, tmp);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ull n, b;
  int i = 0;
  while (cin >> n >> b && (n + b)) {
    printf("Case %d: ", ++i);
    solve(n, b);
  }
}
