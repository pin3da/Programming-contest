#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 222;
int t;
int color[222][222];
int board[222][222];
int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int i, int j, int tar) {
  if (i < 0 || i >= n || j < 0 || j >= m
      || color[i][j] == t || board[i][j] != tar) return 0;

  int ans = 1;
  color[i][j] = t;
  for (int k = 0; k < 4; ++k) {
    ans += dfs(i + dx[k], j + dy[k], tar);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  t = 2;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> board[i][j];


    int best = 1000000;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (color[i][j] < t) {
          best = min(best, dfs(i, j, board[i][j]));
        }
      }
    }
    t++;
    cout << best << endl;
  }
  return 0;
}
