#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int memo[8][8][8][8];

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

struct state {
  int x, y;
  state(int a, int b) : x(a), y(b) {}
};

void fill() {
  memset(memo, -1, sizeof memo);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      memo[i][j][i][j] = 0;
      deque<state> q;
      q.push_back(state(i, j));
      while (!q.empty()) {
        int x = q.front().x,
            y = q.front().y; q.pop_front();

        for (int k = 0; k < 8; ++k) {
          int nx = x + dx[k],
          ny = y + dy[k];
          if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            if (memo[i][j][nx][ny] == -1) {
              memo[i][j][nx][ny] = memo[i][j][x][y] + 1;
              q.push_back(state(nx, ny));
            }
          }
        }
      }
      for (int ii = 0; ii < 8; ++ii) {
        for (int jj = 0; jj < 8; ++jj) {
          assert(memo[i][j][ii][jj] != -1);
        }
      }
    }
  }
}

long long knight_distance(long long x1, long long y1,
    long long x2, long long y2) {
  return memo[x1][y1][x2][y2];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  fill();
  while (cin >> a >> b) {
    cout << "To get from " << a << " to " << b << " takes ";
    cout << knight_distance(a[0] - 'a', a[1] - '1',
        b[0] - 'a', b[1] - '1') << " knight moves." << endl;
  }
  return 0;
}
