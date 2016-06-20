#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 30, MM = 4;
int ok[MN][MM];
long long dp[MN][10];
int N;

long long go(int n, int ant) {
  if (n == N)
    return ant == 0;

  if (dp[n][ant] != -1)
    return dp[n][ant];

  int p = 0, next = 0;
  for (int i = 0; i < 3; ++i) {
    if (!ok[n][i])      p |= 1 << i;
    if (!ok[n + 1][i])  next |= 1 << i;
  }
  int cur = ant | p;
  long long ans = 0;
  if (cur == 0) {
    ans = 3 * go(n + 1, 0);
    for (int i = 1; i <= 7; ++i) {
      if ((next & i) == 0)
        ans += go(n + 1, i);
    }
    if ((next & 1) == 0) ans += go(n + 1, 1);
    if ((next & 4) == 0) ans += go(n + 1, 4);
  }

  if (cur == 1) {
    ans = 2 * go(n + 1, 0);
    if ((next & 2) == 0) ans += go(n + 1, 2);
    if ((next & 4) == 0) ans += go(n + 1, 4);
    if ((next & 6) == 0) ans += go(n + 1, 6);
  }

  if (cur == 2) {
    ans = go(n + 1, 0);
    if ((next & 1) == 0) ans += go(n + 1, 1);
    if ((next & 4) == 0) ans += go(n + 1, 4);
    if ((next & 5) == 0) ans += go(n + 1, 5);
  }

  if (cur == 3) {
    ans = go(n + 1, 0);
    if ((next & 4) == 0) ans += go(n + 1, 4);
  }

  if (cur == 4) {
    ans = 2 * go(n + 1, 0);
    if ((next & 1) == 0) ans += go(n + 1, 1);
    if ((next & 2) == 0) ans += go(n + 1, 2);
    if ((next & 3) == 0) ans += go(n + 1, 3);
  }

  if (cur == 5) {
    ans = go(n + 1, 0);
    if ((next & 2) == 0) ans += go(n + 1, 2);
  }

  if (cur == 6) {
    ans = go(n + 1, 0);
    if ((next & 1) == 0) ans += go(n + 1, 1);
  }

  if (cur == 7) {
    ans = go(n + 1, 0);
  }

  return dp[n][ant] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    N = n;
    for (int i = 0; i < MN; ++i)
      for (int j = 0; j < MM; ++j)
        ok[i][j] = true;

    double x, y;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      ok[int(x)][int(y)] = false;
    }
    ok[n][0] = ok[n][1] = ok[n][2] = false;

    memset(dp, -1, sizeof dp);
    cout << go(0, 0) << endl;
  }
  return 0;
}

