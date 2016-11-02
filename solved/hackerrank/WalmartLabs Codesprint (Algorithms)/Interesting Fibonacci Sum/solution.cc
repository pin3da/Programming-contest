#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

const int MM = 2;
const long long mod = 1e9 + 7;

struct matrix {
  long long m[MM][MM];
  matrix() {
    memset(m, 0, sizeof m);
    //for (int i = 0; i < MM; ++i) m[i][i] = 1;
  }
  void zero() {
    memset(m, 0, sizeof m);
  }

  void init_fibo() {
    m[0][0] = m[0][1] = m[1][0] = 1;
    m[1][1] = 0;
  }

  void print() {
    for (int i = 0; i < MM; ++i) {
      for (int j = 0; j < MM; ++j) {
        cout << m[i][j] << ' ';
      }
      cout << endl;
    }
  }

  matrix operator + (const matrix &a) const {
    matrix r;
    for (int i = 0; i < MM; ++i)
      for (int j = 0; j < MM; ++j)
        r.m[i][j] = (m[i][j] + a.m[i][j]) % mod;
    return r;
  }

  matrix operator * (const matrix &a) const {
    matrix r;
    for (int i = 0; i < MM; ++i) {
      for (int k = 0; k < MM; ++k) {
        if (m[i][k] == 0) continue;
        for (int j = 0; j < MM; ++j) {
          r.m[i][j] = (r.m[i][j] + (m[i][k] * a.m[k][j]) % mod) % mod;
        }
      }
    }
    return r;
  }
};

matrix mod_pow(matrix b, long long e) {
  matrix ans;
  for (int i = 0; i < MM; ++i) ans.m[i][i] = 1;
  while (e) {
    if (e & 1) ans = (ans * b);
    b = (b * b);
    e >>= 1;
  }
  return ans;
}

const int MN = 1e5 + 100;
long long a[MN];
matrix dp[MN];
matrix eye;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  dp[n].zero();
  for (int i = n - 1; i >= 0; --i) {
    dp[i].init_fibo();
    dp[i] = mod_pow(dp[i], a[i]);
    dp[i] = dp[i] * (eye + dp[i + 1]);
  }
  matrix ans;
  for (int i = 0; i < n; ++i)
    ans = ans + dp[i];
  cout << ans.m[0][1] << endl;
}


int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int t; cin >> t;
  for (int i = 0; i < MM; ++i) eye.m[i][i] = 1;
  while (t--)
    solve();

  return 0;
}
