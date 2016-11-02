#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1234;
const int offset = 150;

int N, H;
int d[MN];
int dp[MN][5555];
int col[MN][5555];
int curcol;

int go(int id, int pos) {

  if (col[id][pos] == curcol)
    return dp[id][pos];

  col[id][pos] = curcol;
  if ((id + 2) == N)
    return dp[id][pos] = (d[N - 1] - pos) > H ? MN : 0;

  if (d[id + 1] - pos > H)
    return dp[id][pos] = go(id + 1, pos + H) + 1;

  int best = MN;
  for (int i = d[id + 1]; i <= pos + H; ++i) {
    best = min(best, go(id + 1, i) + (i != d[id + 1]));
  }
  return dp[id][pos] = best;
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  curcol = 1;
  while (cin >> N >> H && (N > 0 && H > 0)) {
    for (int i = 1; i < N; ++i) {
      cin >> d[i];
      d[i] += d[i - 1];
    }

    curcol++;
    int ans = go(0, 0);
    if (ans < MN)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}
