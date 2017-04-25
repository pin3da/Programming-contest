// http://codeforces.com/contest/551/problem/D

using namespace std;
#include<bits/stdc++.h>
#define endl '\n'

const int MN  = 111;
long long mod;

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
  return (res.m[0][0]) % mod;
}

int l2(long long k) {
  int ans = 0;
  while (k > 0) {
    k >>= 1;
    ans++;
  }
  return ans;
}

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1)
      ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  long long n, k, l;
  while (cin >> n >> k >> l >> mod) {

    if (mod == 1 || l < l2(k)) {
      puts("0");
      return 0;
    }

    if (l == 0) {
      if (!k)
        cout << 1 % mod << endl;
      else
        cout << 0 << endl;
      return 0;
    }

    long long res = 1;
    long long fibo = fib(n + 1);
    long long p2   = mod_pow(2, n);
    for (int i = 0; i < l; ++i) {
      if (((k >> i) & 1) == 0)
        res = (res * fibo) % mod;
      else
        res = (res * (mod + p2 - fibo) % mod) % mod;
    }

    cout << (res % mod) << endl;
  }

  return 0;
}
