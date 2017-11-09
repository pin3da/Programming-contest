#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int inf = 4 * int(1e6) + 100;
typedef vector<vector<char>> board;

int get_best(char a, char b, char c, char d) {
  vector<char> tmp = {a, b, c, d};
  sort(tmp.begin(), tmp.end());
  int len = 1, best = 1;
  for (int i = 1; i < 4; i++) {
    if (tmp[i] == tmp[i - 1]) {
      len++;
    } else {
      len = 1;
    }
    best = max(best, len);
  }
  return 4 - best;
}


const int MN = 1e5 + 10;
int cost_row[MN];
int cost_col[MN];

int fix_row(board &g, int col) {
  if (cost_row[col] != -1) return cost_row[col];
  int total = g[0].size();
  int mirror = total - 1 - col;
  if (col == mirror) return cost_row[col] = 0;

  int ans = 0;
  int n = g.size();
  for (int i = 0; i < n; i++) {
    ans += g[i][col] != g[i][mirror];
  }
  return cost_row[col] = ans;
}

int fix_col(board &g, int col) {
  if (cost_col[col] != -1) return cost_col[col];
  int total = g[0].size();
  int mirror = total - 1 - col;
  int n = g.size();
  int ans = 0;

  if (col == mirror) {
    for (int i = 0; i < n / 2; i++) {
      ans += g[i][col] != g[n - 1 - i][col];
    }
    return cost_col[col] = ans;
  }

  int top = n / 2;

  for (int i = 0; i < top; i++) {
    ans += get_best(
        g[i][col],
        g[i][mirror],
        g[n - 1 - i][col],
        g[n - 1 - i][mirror]
        );
  }

  if (n & 1) {
    ans += g[n / 2][col] != g[n / 2][mirror];
  }
  return cost_col[col] = ans;
}

map<int, int> dp[MN / 2 + 100];

int go(board &g, int col, int k, int last, int t) {
  if (col >= last) {
    if (k <= 0) return 0;
    return inf;
  }

  if (dp[col].count(k)) return dp[col][k];

  int op2 = go(g, col + 1, k, last, t) + fix_row(g, col);
  if (k) {
    int has_mirror = true;
    if (col == (last - 1) && t)
      has_mirror = false;
    int op1 = go(g, col + 1, k - 1 - has_mirror, last, t) + fix_col(g, col);
    return dp[col][k] = min(op1, op2);
  } else {
    return dp[col][k] = op2;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m, k; cin >> n >> m >> k;
  board g(n, vector<char> (m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }

  memset(cost_row, -1, sizeof cost_row);
  memset(cost_col, -1, sizeof cost_col);
  cout << go(g, 0, k, m / 2 + (m & 1), m & 1) << endl;

  return 0;
}
