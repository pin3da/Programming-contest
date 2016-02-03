#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool dfs(vector<vector<int>> &g, vector<vector<int>> &vi, int x, int y) {

  vi[x][y] = true;
  if (x == 4 && y == 4)
    return true;

  int ok = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5
        && !vi[nx][ny] && g[nx][ny] == 0) {
      ok |= dfs(g, vi, nx, ny);
    }
  }
  return ok;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    vector<vector<int>> g(5, vector<int>(5));
    for (auto &i : g)
      for (auto &j : i)
        cin >> j;

    vector<vector<int>> vi(5, vector<int>(5));
    if (dfs(g, vi, 0, 0))
      cout << "COPS" << endl;
    else
      cout << "ROBBERS" << endl;
  }
  return 0;
}
