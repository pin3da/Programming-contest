// WA
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1234;
int bucket[MN];
int bef[MN];

const long long mod = 1e9 + 7;

long long dp[MN][MN][2][2];
int T;

long long go(vector<string> &a, int i, int j, bool t1, bool t2) {
  if (i > j) return 0;
  if (i == j) {
    return 1;
  }

  if (dp[i][j][t1][t2] != -1)
    return dp[i][j][t1][t2];

  int ii = i - bef[bucket[i]],
  jj = j - bef[bucket[j]];

  long long ans = 0;
  if (a[bucket[i]][ii] == a[bucket[j]][jj]) {
    int nt1 = (bucket[i] == bucket[i + 1]);
    int nt2 = (bucket[j] == bucket[j - 1]);
    ans = (ans + (go(a, i + 1, j - 1, nt1, nt2) + 1)) % mod;
  } else {

    int state = 0;

    if ((bucket[i] != bucket[i + 1] && t1) ||
        (bucket[i] == bucket[i + 1])) {
      int nt = bucket[i] == bucket[i + 1] ? t1 : 0;
      ans = (ans + go(a, i + 1, j, nt, t2)) % mod;
      state |= 1;
    }

    if ((bucket[j] != bucket[j - 1] && t2) ||
        (bucket[j] == bucket[j - 1])) {
      int nt = bucket[j] == bucket[j - 1] ? t2 : 0;
      ans = (ans + go(a, i, j - 1, t1, nt)) % mod;
      state |= 2;
    }

    if (state == 3) {
      int nt1 = bucket[i] == bucket[i + 1] ? t1 : 0;
      int nt2 = bucket[j] == bucket[j - 1] ? t2 : 0;
      long long tmp =  go(a, i + 1, j - 1, nt1, nt2);
      ans = (ans + mod - tmp) % mod;
    }
  }

  return dp[i][j][t1][t2] = ans;
}

void solve() {
  int n; cin >> n;
  vector<string> a(n);
  int totlen = 0;
  memset(bucket, -1, sizeof bucket);
  memset(bef, 0, sizeof bef);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) bef[i] = bef[i - 1] + a[i - 1].size();
    for (size_t k = 0; k < a[i].size(); ++k) {
      bucket[totlen++] = i;
    }
  }
  T = totlen;
  memset(dp, -1, sizeof dp);
  cout << go(a, 0, totlen - 1, 0, 0) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
