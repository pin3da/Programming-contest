#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN  = 5;
const long long mod = 1000000007LL;

struct matrix {
  int r, c;
  long long m[MN][MN];

  matrix () {}
  matrix (int _r, int _c) : r (_r), c (_c) {
    memset(m, 0, sizeof m);
  }

  void clear() {
    r = c = 0;
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


matrix coef, res;

long long fib(long long n) {
  coef.clear();
  res.clear();
  res.r = res.c = coef.r = coef.c = 2;
  coef.m[0][0] = 1;
  coef.m[0][1] = 1;
  coef.m[1][0] = 1;

  matrix_pow(coef, n, res);
  return (res.m[0][1]) % mod;
}

long long sum_sq(int x) {
  return (fib(x + 1) * fib(x)) % mod;
}

long long sum_con(int x) {
  x--;
  if (x <= 0) return 0;
  return (((fib(x + 1) * fib(x + 1)) % mod) - 1 + (x & 1) + mod) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int a, b, n;
  while (cin >> a >> b >> n) {
    if ((a + b + n) == 0) break;
    if (b < a) swap(a, b);
    long long ans = 0;
    int k0 = b - a;
    int k1 = k0 + 1;
    /*for (int i = 0; i < n; ++i) {
      int c = a + i;
      ans += fib[k0] * fib[c] * fib[c - 1] + fib[k1] * fib[c] * fib[c];
    }*/
    ans = (fib(k1) * (sum_sq(a + n - 1) - sum_sq(a - 1) + mod) % mod) % mod
        + (fib(k0) * (sum_con(a + n - 1) - sum_con(a - 1)+ mod) % mod) % mod;
    cout << ans % mod << endl;
  }

  return 0;
}
