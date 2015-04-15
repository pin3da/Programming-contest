using namespace std;
#include <bits/stdc++.h>

const int MN = 50;
int dp[MN][6][4];

bool is_vow(char c) {
  return (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
}

int go(const string &line, int i, int c, int v) {
  if (i == line.size())
    return 2;

  if (dp[i][c][v] != -1)
    return dp[i][c][v];

  if (line[i] == '?') {
    int op1 = (c >= 4) ? 1 : go(line, i + 1, min(c + 1, 5), 0);
    int op2 = (v >= 2) ? 1 : go(line, i + 1, 0, min(v + 1, 3));
    return dp[i][c][v] = op1 | op2;
  }

  if (is_vow(line[i])) {
    if (v >= 2)
      return dp[i][c][v] = 1;
    return dp[i][c][v] = go(line, i + 1, 0, min(v + 1, 3));
  }

  if (c >= 4)
    return dp[i][c][v] = 1;
  return dp[i][c][v] = go(line, i + 1, min(c + 1, 5), 0);
}

void solve() {
  string line;
  cin >> line;
  memset(dp, -1, sizeof dp);
  int op = go(line, 0, 0, 0);
  if (op == 1)
    puts("BAD");
  else if (op == 2)
    puts("GOOD");
  else
    puts("MIXED");
}

int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
}
