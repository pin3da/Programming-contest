class Solution {
  const int dx[4] = {-1, 0, 1, 0};
  const int dy[4] = {0, -1, 0, 1};

  public:
  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;

    const int rows = board.size(), cols = board[0].size();
    vector<vector<char>> auxBoard(rows + 2, vector<char>(cols + 2, 'O'));
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        auxBoard[i + 1][j + 1] = board[i][j];

    deque<pair<int, int>> q;
    q.push_back({0, 0});
    auxBoard[0][0] = 'm';

    while (q.size()) {
      auto cur = q.front(); q.pop_front();
      for (int k = 0; k < 4; k++) {
        int nx = cur.first + dx[k], ny = cur.second + dy[k];
        if (nx >= 0 && nx < rows + 2 && ny >= 0 && ny < cols + 2 && auxBoard[nx][ny] == 'O') {
          auxBoard[nx][ny] = 'm';
          q.emplace_back(nx, ny);
        }
      }
    }

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        board[i][j] = auxBoard[i + 1][j + 1] == 'm' ? 'O' : 'X';

  }
};
