using namespace std;
#include<bits/stdc++.h>
#define clear(x) memset(x, 0, sizeof x)
#define D(x)  cout << #x " = " << (x) << endl

const int MN = 15;
int sizes[MN];
int dp[MN];

const long long mod = 1000000007;

struct matrix {
  int r, c;
  long long  m[MN][MN];

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

  long long n;
  int k;
  cin >> n >> k;
  int tmp;

  matrix base(MN, MN);

  for (int i = 1; i < MN; ++i)
    base.m[i - 1][i] = 1;

  for (int i = 0; i < k; ++i) {
    cin >> sizes[i];
    base.m[MN - 1][MN - sizes[i]] = 1;
  }


  clear(dp); // dp[i] keeps the answer for f(i + 1).
  for (int i = 0; i < MN; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i + 1 - sizes[j] < 0) continue;
      if ((i + 1 - sizes[j]) == 0)
        dp[i] += 1;
      else
        dp[i] += dp[i - sizes[j]];
    }
  }


  if (n <= MN) {
    cout << (dp[n - 1] * 2) % mod << endl;
    return 0;
  }

  matrix ans(MN, MN);
  matrix_pow(base, n - MN, ans);

  long long res = 0;
  for (int i = 0; i < MN; ++i)
    res = (res + ( ans.m[MN - 1][i] * dp[i] ) % mod ) % mod;

  cout << (res * 2) % mod << endl;

  return 0;
}
