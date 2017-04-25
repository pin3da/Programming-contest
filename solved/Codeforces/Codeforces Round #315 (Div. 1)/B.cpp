// http://codeforces.com/contest/568/problem/B

using namespace std;
#include <bits/stdc++.h>

const long long mod = 1000000007;
const int MN = 4004;

long long _c[MN][MN];
long long c(int a, int b) {
  if (b == 0 || a == 0) return b == 0;
  if (_c[a][b] != -1) return _c[a][b];
  return _c[a][b] = (c(a - 1, b - 1) + c(a - 1, b)) % mod;
}

long long _d[MN];
long long d(int n) {
  if (n == 0) return 1;
  if (_d[n] != -1)  return _d[n];
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans = (ans + (c(n - 1, i) * d(i)) % mod) % mod;
  return _d[n] = ans;
}

int main() {
  memset(_c, -1, sizeof _c);
  memset(_d, -1, sizeof _d);
  int n;
  while (cin >> n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      ans = (ans + (c(n, i) * d(n - i)) % mod ) % mod;
    cout << ans << endl;
  }

  return 0;
}