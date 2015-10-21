using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN  = 55;

struct matrix {
  int r, c;
  unsigned m[MN][MN];
  matrix() {}

  void init(int _r, int _c) {
    r = _r, c = _c;
    memset(m, 0, sizeof m);
  }

  void print() {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        cout << m[i][j] << " ";
      cout << endl;
    }
  }

  unsigned x[MN][MN];
  matrix & operator *= (const matrix &o) {
    memset(x, 0, sizeof x);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
        if (m[i][k] != 0)
          for (int j = 0; j < c; ++j) {
            x[i][j] = x[i][j] + m[i][k] * o.m[k][j];
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


matrix a, ans;

void solve() {
  int d; cin >> d;
  string alpha, pattern;
  cin >> alpha >> pattern;

  int n = pattern.size();
  a.init(n, n);
  ans.init(n, n);

  for (int i = 0; i < n; ++i) {
    string base = pattern.substr(0, i);
    base.push_back(alpha[0]);
    for (int j = 0; j < alpha.size(); ++j) {
      base[i] = alpha[j];
      for (int k = i + 1; k >= 0; --k) {
        // Failure function.
        if (k == 0 || base.substr(i + 1 - k, k) == pattern.substr(0, k)) {
          if (k != n) // avoid match.
            a.m[i][k]++;
          break;
        }
      }
    }
  }

  matrix_pow(a, d, ans);
  unsigned tot = 0;
  for (int i = 0; i < n; ++i)
    tot += ans.m[0][i];
  printf("%u\n", tot);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
