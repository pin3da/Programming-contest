class Solution {
  bool check(vector<string> &board, int x, int y) {
    int n = board.size();
    int in_row = 0, in_col = 0;
    for (int i = 0; i < n; i++) {
      in_row += (board[x][i] == 'Q');
      in_col += (board[i][y] == 'Q');
      if (in_row > 1 || in_col > 1)
        return false;
    }

    int in_diag = 0;

    int i = x, j = y;
    while (i >= 0 && j < n) {
      in_diag += (board[i][j] == 'Q');
      if (in_diag > 1) return false;
      i--; j++;
    }

    i = x + 1, j = y - 1;
    while (j >= 0 && i < n) {
      in_diag += (board[i][j] == 'Q');
      if (in_diag > 1) return false;
      i++; j--;
    }

    in_diag = 0;
    i = x, j = y;
    while (i < n && j < n) {
      in_diag += (board[i][j] == 'Q');
      if (in_diag > 1) return false;
      i++; j++;
    }
    i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0) {
      in_diag += (board[i][j] == 'Q');
      if (in_diag > 1) return false;
      i--; j--;
    }

    return true;
  }

  void solve(int n, int i, int j, int queens, int &ans, vector<string> &board) {
    if (i == (n - 1) && j == n) {
      if (queens == n)
        ans++;
      return;
    }

    if (j >= n) {
      solve(n, i + 1, 0, queens, ans, board);
      return;
    }

    if (queens == n) {
      ans++;
      return;
    }

    solve(n, i, j + 1, queens, ans, board);
    board[i][j] = 'Q';
    if (check(board, i, j)) {
      solve(n, i, j + 1, queens + 1, ans, board);
    }
    board[i][j] = '.';
  }

  public:
  int totalNQueens(int n) {
    int ans = 0;
    vector<string> board(n, string(n, '.'));
    solve(n, 0, 0, 0, ans, board);
    return ans;
  }
};

