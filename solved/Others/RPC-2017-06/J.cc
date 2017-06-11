#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int H, int W, int x, int y) {
  return (x >= 0 && x < H && y >= 0 && y < W);
}

long long dp[26][26][4];

long long go(int H, int W, int dir) {
  int x, y;
  if (H == 1 || W == 1) {
    return 1;
  }

  if (dp[H][W][dir] != -1) {
    return dp[H][W][dir];
  }

  if (dir == 0) {
    x = H - 1;
    y = 0;
  }
  if (dir == 1) {
    x = 0;
    y = 0;
  }
  if (dir == 2) {
    x = 0;
    y = W - 1;
  }
  if (dir == 3) {
    x = H - 1;
    y = W - 1;
  }
  long long ans = 0;

  int top = (dir & 1) ? W : H;
  for (int i = 0; i < top ; ++i) {
    int nx = x + dx[dir] * i + dx[(dir + 1) % 4];
    int ny = y + dy[dir] * i + dy[(dir + 1) % 4];
    if (valid(H, W, nx, ny)) {
      if (dir == 0) {
        ans += go(i + 1, W - 1, (dir + 1) % 4);
      }
      if (dir == 1) {
        ans += go(H - 1, i + 1,(dir + 1) % 4);
      }
      if (dir == 2) {
        ans += go(i + 1, W - 1, (dir + 1) % 4);
      }
      if (dir == 3) {
        ans += go(H - 1, i + 1, (dir + 1) % 4);
      }
    }
  }
  return dp[H][W][dir] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  memset(dp, -1, sizeof dp);
  while (tc--) {
    int r, c; cin >> r >> c;
    cout << go(r, c, 0) << endl;
  }
  return 0;
}
