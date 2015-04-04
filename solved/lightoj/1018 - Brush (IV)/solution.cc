using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << " = " << (x) << endl

const int MN = 20;
const int inf = 666;
int n;
int cl[MN][MN];

vector<int> x(MN), y(MN);

int dp[1 << MN];

int go(int mask) {
  if (mask == ((1 << n) - 1))
    return 0;

  if (dp[mask] != -1)
    return dp[mask];

  if (__builtin_popcount(mask) == (n - 1))
    return dp[mask] = 1;

  int best = inf;
  int i;
  for (i = 0; ((mask >> i) & 1); ++i);

  for (int j = 0; j < n; ++j)
    if ((i != j) && !((mask >> j) & 1))
      best = min(best, go(mask | cl[i][j]) + 1);

  return dp[mask] = best;
}

bool collinear(int i, int j, int k) {
  return ((x[i] - x[j]) * (y[k] - y[j]) - (y[i] - y[j]) * (x[k] - x[j])) == 0;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  memset(cl, 0, sizeof cl);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k)
        if ((i != j) && collinear(i, j, k)) {
          cl[i][j] |= (1 << k);
        }
    }

  memset(dp, -1, sizeof dp);
  printf("%d\n", go(0));

}


int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
