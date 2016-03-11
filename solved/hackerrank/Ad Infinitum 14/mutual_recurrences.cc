#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

const long long mod = 1000 * 1000 * 1000;

long long mul(long long x, long long y) {
  long long ans = x * y;
  if (ans >= mod)
    ans %= mod;
  return ans;
}

long long add(long long x, long long y) {
  long long ans = x + y;
  if (ans >= mod)
    ans -= mod;
  return ans;
}

long long sub(long long x, long long y) {
  long long ans = x - y;
  if (ans < 0)
    ans += mod;
  return ans;
}

const int M = 30;
struct matrix {
  long long a[M][M];

  matrix() {
    for (int i = 0; i < M; ++i)
      fill(a[i], a[i] + M, 0);
  }

  long long* operator[](int x) {
    return a[x];
  }

  matrix operator * (matrix &to) {
    matrix ans;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j)
        for (int k = 0; k < M; ++k)
          ans[i][j] = add(ans[i][j], mul(a[i][k], to[k][j]));
    return ans;
  }

  vector<long long> operator * (vector<long long> to) {
    vector<long long> ans(24);
    for (int i = 0; i < 24; ++i)
      for (int j = 0; j < 24; ++j)
        ans[i] = add(ans[i], mul(a[i][j], to[j]));
    return ans;
  }

};

matrix mod_pow(matrix base, long long n) {
  matrix ans;
  for (int i = 0; i < M; ++i) ans[i][i] = 1;
  while (n > 0) {
    if (n & 1)
      ans = ans * base;
    base = base * base;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int a, b, c, d, e, f, g, h;
  long long n;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> n;
  matrix A;
  A[0][a - 1]++;
  A[0][10 + b - 1]++;
  A[0][10 + c - 1]++;
  A[0][22]++;

  A[10][10 + e - 1]++;
  A[10][f - 1]++;
  A[10][g - 1]++;
  A[10][20]++;

  for (int i = 1; i <= 9; ++i) {
    A[i][i - 1] = 1;
    A[i + 10][10 + i - 1] = 1;
  }


  A[20][20] = h;
  A[20][21] = h;
  A[21][21] = h;

  A[22][22] = d;
  A[22][23] = d;
  A[23][23] = d;

  vector<long long> r(24, 1);
  r[20] = 0;
  r[21] = 1;
  r[22] = 0;
  r[23] = 1;


  A = mod_pow(A, n + 1);

  r = A * r;
  cout << r[0] << " " << r[10] << endl;
}


int main() {
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
