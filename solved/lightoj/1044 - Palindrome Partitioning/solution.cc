using namespace std;
#include <bits/stdc++.h>

const int inf = 1 << 30;

const int MN = 1111;
int dp[MN];
int pl[MN][MN];

bool pal(const string &line, int b, int e) {
  if (b >= e)
    return true;
  if (pl[b][e] != -1)
    return pl[b][e];
  return pl[b][e] = (line[b] == line[e]) && pal(line, b + 1, e - 1);
}

int go(const string &line, int b) {
  if (b == line.size())
    return 0;

  if (dp[b] != -1)
    return dp[b];

  int best = inf;
  for (int i = b; i < line.size(); ++i) {
    if (pal(line, b, i))
      best = min(best, 1 + go(line, i + 1));
  }
  return dp[b] = best;
}

void solve() {
  string line;
  cin >> line;
  memset(dp, -1, sizeof dp);
  memset(pl, -1, sizeof pl);
  printf("%d\n", go(line, 0));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
