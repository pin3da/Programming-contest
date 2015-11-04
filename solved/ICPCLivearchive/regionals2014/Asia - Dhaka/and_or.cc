/**
 * TLE
 * */

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long target;
long long dp[66][3][3];
int p, M;

long long go(int i, int seen, int top) {
  if (i == M)
    return seen;

  if (dp[i][seen][top] != -1)
    return dp[i][seen][top];

  int m = top? ((target >> ((M - 1) - i)) & 1) : 1;
  long long ans = 0;
  for (int j = 0; j <= m; ++j) {
    ans += go(i + 1, seen | (j && (i == p)), top && (j == m));
  }
  return dp[i][seen][top] = ans;
}

void solve() {
  long long a, b;
  cin >> b >> a;
  M = ceil(log2(a)) + 1;
  vector<long long> o_a(M), o_b(M);
  target = a;

  for (int i = 0; i < M; ++i) {
    memset(dp, -1, sizeof dp);
    p = i;
    o_a[i] = go(0, 0, 1);
    // cout << o_a[i] << " ";
  }
  // cout << endl;

  target = b - 1;
  for (int i = 0; i < M; ++i) {
    memset(dp, -1, sizeof dp);
    p = i;
    o_b[i] = go(0, 0, 1);
    // cout << o_b[i] << " ";
  }
  // cout << endl;

  long long ans_or = 0, ans_and = 0;
  for (int i = 0; i < M; ++i) {
    if (o_a[i] - o_b[i] > 0) {
      ans_or |= (1LL << ((M - 1) - i));
    }
    long long z_a = a - o_a[i],
              z_b = b - 1 - o_b[i];

    if (z_a - z_b == 0) {
      ans_and |= (1LL << ((M - 1) - i));
    }
  }

  printf("%lld %lld\n", ans_or, ans_and);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
