using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN  = 4;
const long long mod = 1000000007;

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
            x[i][j] = x[i][j] + m[i][k] * o.m[k][j];
            if (x[i][j] >= mod) {
              x[i][j] = x[i][j] % mod;
            }
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
    if (e & 1) {
      res *= b;
    }
    if ((e >>= 1) == 0) break;
    b *= b;
  }
}

void solve() {
  long long n, x, m, y, k;
  cin >> n >> x >> m >> y >> k;
  matrix m1(2, 2), m2(2, 2), m3(2, 2);
  m1.m[0][0] = m2.m[0][0] = m3.m[0][0]= 0;
  m1.m[0][1] = m2.m[0][1] = m3.m[0][1]= 1;
  m1.m[1][0] = m2.m[1][0] = m3.m[1][0]= 1;
  m1.m[1][1] = m2.m[1][1] = m3.m[1][1]= 1;

  matrix_pow(m1, n, m1);
  matrix_pow(m2, m, m2);

  long long c  = m1.m[1][0], d  = m1.m[1][1];
  long long cp = m2.m[1][0], dp = m2.m[1][1];

  if ((c * dp - d * cp) == 0) {
    puts("Impossible");
    return;
  }

  long long a0 = (x * dp - y * d) / (c * dp - d * cp);
  long long b0 = (c * y - x * cp) / (c * dp - d * cp);
  if (((x * dp - y * d) % (c * dp - d * cp)) || ((c * y - x * cp) % (c * dp - d * cp))
        || a0 < 0 || b0 < 0) {
    puts("Impossible");
    return;
  }
  matrix_pow(m3, k, m3);

  printf("%lld\n", (m3.m[1][0] * a0 + m3.m[1][1] * b0) % mod);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
