using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 66;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int left(int dir) {
  return (dir + 3) % 4;
}

int right(int dir) {
  return (dir + 1) % 4;
}

void solve() {

  vector<vector<int> > g(MN, vector<int>(MN, 0));
  int x, y;
  string line;
  cin >> x >> y >> line;
  g[x][y] = 1;
  int dir = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == 'F') {
      x += dx[dir];
      y += dy[dir];
      g[x][y]++;
    } else if (line[i] == 'R') {
      dir = right(dir);
    } else {
      dir = left(dir);
    }
  }

  int ans = 0;
  for (int i = 0; i < MN; ++i) {
    for (int j = 0; j < MN; ++j) {
      if (g[i][j] > 1)
        ans ++;
    }
  }

  cout << x << " " << y << " " << ans << endl;


}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
