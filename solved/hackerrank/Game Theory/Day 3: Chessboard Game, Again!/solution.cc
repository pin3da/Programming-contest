#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int dp[16][16];

int dx[] = {-2, -2, 1, -1};
int dy[] = {1, -1, -2, -2};

int go(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  vector<int> mex(5);
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < 15 && ny >= 0 && ny < 15)
      mex[go(nx, ny)] = true;
  }
  for (int i = 0; i < 5; ++i) {
    if (!mex[i])
      return dp[x][y] = i;
  }
  assert(false);
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc; cin >> tc;
  memset(dp, -1, sizeof dp);

  while (tc--) {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
      int x, y; cin >> x >> y;
      ans ^= go(x - 1, y - 1);
    }
    puts(ans > 0 ? "First" : "Second");
  }

  return 0;
}
