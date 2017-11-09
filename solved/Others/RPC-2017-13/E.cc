#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int n;

bool is_valid(int x) {
  return (x >= 0 && x < n);
}

void paint_tree(int x, int y, int h, vector<vector<char>> &board) {
  y--;
  // cout << x << " " << y << endl;
  for (int i = 0; i < 3; i++) {
    // cout << x << " " << y + i << endl;
    if (is_valid(y + i) && is_valid(x)) {
      if (i == 1) {
        if (h == 0) {
          board[x][y + i] = 'o';
        } else {
          board[x][y + i] = '|';
        }
      } else {
        board[x][y + i] = '_';
      }
    }
  }
  x--;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < 3; j++) {
      // cout << x - i << " " << y + j << endl;
      if (is_valid(x - i) && is_valid(y + j)) {
        if (j == 1) {
          board[x - i][y + j] = '|';
        } else if ( j == 0) {
          board[x - i][y + j] = '/';
        } else {
          board[x - i][y + j] = '\\';
        }
      }
    }
  }
  if (h == 0) return;
  x -= h;
  // cout << x << " " << y + 1 << endl << endl;
  if (is_valid(x) && is_valid(y + 1)) {
    board[x][y + 1] = '^';
  }
  return;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int q, h, x, y;

  while (cin >> n >> q) {
    vector<vector<char>> board(n, vector<char>(n, '.'));
    for (int i = 0; i < q; i++) {
      cin >> h >> x >> y;
      paint_tree( n - y - 1, x, h, board);
    }
    cout << string(n + 2, '*') << endl;
    for (int i = 0; i < n; i++) {
      cout << '*';
      for (int j = 0; j < n; j++) cout << board[i][j];
      cout << '*' << endl;
    }
    cout << string(n + 2, '*') << endl;
    cout << endl;
  }
  return 0;
}
