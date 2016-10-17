#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 1e5 + 100;
int a[MN];

int n;
int dp[MN][66];

int f(int i, long long len) {
  if (len == 0) return a[i];

  int zeros = __builtin_clzll(len);
  if (dp[i][zeros] != -1)
    return dp[i][zeros];

  long long t = 0;
  for (int j = 61; j >= 0; --j) {
    if ((len >> j) & 1) {
      len ^= (1LL << j);
      t = (1LL << j);
      break;
    }
  }
  t %= n;
  return dp[i][zeros] = f(i, len) ^ f((i + t) % n, len);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long m;
  while (cin >> n >> m) {
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < n; ++i)
      cin >> a[i];

    m--;
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << f(i, m);
    }
    cout << endl;
  }

  return 0;
}
