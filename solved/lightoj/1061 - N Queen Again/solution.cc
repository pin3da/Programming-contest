using namespace std;
#include <bits/stdc++.h>

const int MN = 666;
const int inf = 1 << 30;

struct pos{
  int x, y;
  pos() {}
  pos(int a, int b) : x(a), y(b) {}
};

pos solutions[MN][8];
int num_sol;


bool empty(int &mask, int &index) {
  return ((mask >> index) & 1) == 0;
}

void precompute(pos *cur, int row, int cols, int d1, int d2) {
  if (row == 8) {
    for (int i = 0; i < 8; ++i) {
      solutions[num_sol][i] = cur[i];
    }
    num_sol++;
    return;
  }

  for (int i = 0; i < 8; ++i) {
    int right = row + i;
    int left  = 7 - row + i;
    if (empty(cols, i) && empty(d1, right) && empty(d2, left)) {
      cur[row] = pos(row, i);
      precompute(cur, row + 1, cols | (1 << i), d1 | (1 << right), d2 | (1 << left));
    }
  }
}

int cost(pos &a, pos &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  if (dx == 0 && dy == 0) return 0;
  if (dx == 0 || dy == 0) return 1;
  if (fabs(dx) == fabs(dy)) return 1;
  return 2;
}

int dp[(1 << 8) + 10];
int go(pos *target, pos *cur, int mask) {
  if (dp[mask] != -1)
    return dp[mask];
  if (mask == (1 << 8) - 1)
    return dp[mask] = 0;

  int best = inf;
  int queen = __builtin_popcount(mask);
  for (int i = 0; i < 8; ++i) {
    if(!((mask >> i) & 1)) {
      best = min(best, go(target, cur, mask | (1 << i)) + cost(target[i], cur[queen]));
    }
  }

  return dp[mask] = best;
}

void solve() {
  pos board[8];
  char t;
  int q = 0;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> t;
      if (t == 'q') {
        board[q++] = pos(i, j);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < num_sol; ++i) {
    memset(dp, -1, sizeof dp);
    ans = min(ans, go(solutions[i], board, 0));
  }
  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  num_sol = 0;
  pos cur[8];
  precompute(cur, 0, 0, 0, 0);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
