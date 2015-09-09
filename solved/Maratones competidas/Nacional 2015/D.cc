using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct frac {
  long long x, y;
  frac() : x(0), y(1) {}
  frac(long long a) {
    x = a; y = 1;
  }
  frac(long long a, long long b) {
    long long g = __gcd(a, b);
    x = a / g;
    y = b / g;
  }

  frac operator *(const frac &o) {
    return frac(x * o.x, y * o.y);
  }

  frac operator -(const frac &o) {
    long long a = x * o.y - y * o.x;
    long long b = y * o.y;
    return frac(a, b);
  }

  bool operator < (const frac &o) const {
    long double tx = x, ty = y, ox = o.x, oy = o.y;
    return tx / ty < ox / oy;
  }
};

const int MM = 20;
int m[MM];
int a[MM][MM];
int b[MM][MM];
int c[MM][MM];

int n;
frac dp[MM][1025];
int seen[MM][1025];

frac go(int i, int cur) {
  if (i == n)
    return frac(1);

  if (seen[i][cur])
    return dp[i][cur];

  frac ans(0);
  for (int j = 0; j < m[i]; ++j) {
    if (c[i][j] <= cur) {
      ans = max(ans, frac(a[i][j], b[i][j]) * go(i + 1, cur - c[i][j]));
    }
  }
  seen[i][cur] = true;
  return dp[i][cur] = ans;
}

int main() {
  //ios_base::sync_with_stdio(false);cin.tie(NULL);

  int k;
  while (cin >> n >> k) {
    memset(m, 0, sizeof m);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    memset(seen, 0, sizeof seen);
    for (int i = 0; i < n; ++i)
      cin >> m[i];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m[i]; ++j) {
        cin >> a[i][j] >> b[i][j] >> c[i][j];
        a[i][j] = b[i][j] - a[i][j];
      }
    }

    frac ans = go(0, k);
    ans = frac(1) - ans;
    cout << ans.x << "/" << ans.y << endl;
  }
  return 0;
}
