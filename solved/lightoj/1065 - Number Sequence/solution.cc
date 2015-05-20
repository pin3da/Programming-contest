using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN  = 5;
int mod = 10000;

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

void solve() {
  int a, b, n, m;
  cin >> a >> b >> n >> m;
  mod = 1;
  while (m-- > 0) {
    mod *= 10;
  }
  if (n == 0) {
    printf("%d\n", a % mod);
    return;
  }
  if (n == 1) {
    printf("%d\n", b % mod);
    return;
  }

  matrix base(2, 2);
  matrix ans(2, 2);
  base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
  base.m[1][1] = 0;
  matrix_pow(base, n - 1, ans);
  printf("%d\n", ((ans.m[0][0] * b) % mod + (ans.m[0][1] * a) % mod) % mod);
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
}
