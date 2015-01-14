using namespace std;
#include <bits/stdc++.h>

int board[9][9];

void print() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j)
      printf("%d", board[i][j]);
    printf("\n");
  }
}

bool valid(int r, int c, int v) {

  for (int i = 0; i < 9; ++i)
    if ((board[r][i] == v) or board[i][c] == v) return false;

  int init_i = (r / 3) * 3;
  int init_j = (c / 3) * 3;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (board[init_i + i][init_j + j] == v) return  false;

  return true;
}

bool find_best(int &r, int &c) {
  int best = 100;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] != 0) continue;

      int cur = 0;
      for (int k = 1; k < 10; ++k)
        if (valid(i, j, k))
          cur++;

      if (cur < best) {
        r = i;
        c = j;
        best = cur;
      }
    }
  }

  if (best < 10) return true;
  return false;
}

bool solve() {

  int i, j;
  if (!find_best(i, j))
    return true;
  for (int k = 1; k < 10; ++k) {
    if (!valid(i, j, k)) continue;
    board[i][j] = k;
    if (solve())
      return true;
  }
  board[i][j] = 0;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d:\n", i + 1);
    char t;
    int cur = 0;
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        cin >> t;
        if (t == '.')
          board[i][j] = 0;
        else {
          board[i][j] = t - '0';
          cur++;
        }
      }
    solve();
    print();
  }

  return 0;
}
