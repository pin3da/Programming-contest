#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};

  vector<vector<int>> color;

  bool valid(vector<vector<int>> &g, int nx, int ny) {
    int len = g.size();
    return (nx >= 0 && nx < len && ny >= 0 && ny < len);
  }

  int bfs(vector<vector<int>> &g, int i, int j, int col) {
    deque<pair<int, int>> q;
    q.emplace_back(i, j);
    color[i][j] = col;
    int size = 1;
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop_front();
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (valid(g, nx, ny) && g[nx][ny] == 1 && color[nx][ny] == -1) {
          color[nx][ny] = col;
          size++;
          q.emplace_back(nx, ny);
        }
      }
    }
    return size;
  }

 public:
  int largestIsland(vector<vector<int>> &grid) {
    const int n = grid.size();
    color.assign(n, vector<int>(n, -1));

    vector<int> size;

    int cur_color = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (color[i][j] == -1 && grid[i][j] == 1)
          size.push_back(bfs(grid, i, j, cur_color++));
      }
    }

    int best = size.size() ? *max_element(size.begin(), size.end()) : 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          set<int> colors;
          for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (valid(grid, nx, ny) && color[nx][ny] != -1) {
              colors.insert(color[nx][ny]);
            }
          }
          int local = 1;
          for (auto c : colors) local += size[c];
          best = max(best, local);
        }
      }
    }
    return best;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> g;
  g.push_back({0, 0});
  g.push_back({0, 0});
  cout << sol.largestIsland(g) << endl;
  return 0;
}
