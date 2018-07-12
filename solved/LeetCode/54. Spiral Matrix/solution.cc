class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      const vector<int> dx = {0, 1, 0, -1};
      const vector<int> dy = {1, 0, -1, 0};

      vector<int> answer;
      if (matrix.size() == 0) return answer;

      int n = matrix.size();
      int m = matrix[0].size();

      vector<vector<int>> seen_before(n, vector<int>(m));

      int x = 0, y = 0, curr_direction = 0;

      while (answer.size() < (n * m)) {
        answer.push_back(matrix[x][y]);
        seen_before[x][y] = true;
        x += dx[curr_direction];
        y += dy[curr_direction];

        if ((x < 0 || x >= n || y < 0 || y >= m) || seen_before[x][y]) {
          x -= dx[curr_direction];
          y -= dy[curr_direction];
          curr_direction = (curr_direction + 1) % 4;
          x += dx[curr_direction];
          y += dy[curr_direction];
        }
      }

      return answer;
    }
};
