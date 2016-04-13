#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void printg(vector<vector<char>> &g) {
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << g[i][j];
    }
    cout << endl;
  }
  cout << "@" << endl;
}

int x, y;

bool move(vector<vector<char>> &g, int iter, int dir) {
  int n = g.size();

  for (int i = 0; i < iter; ++i) {
    int nx = x + dx[dir],
        ny = y + dy[dir];

    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
      return false;

    g[x][y] = 'O';
    x = nx;
    y = ny;
    g[x][y] = 'X';
    printg(g);
  }
  return true;
}

void solve(int n) {
  vector<vector<char>> g(n, vector<char> (n, 'O'));
  x = n >> 1,
  y = n >> 1;

  int iter = 0;
  g[x][y] = 'X';
  printg(g);
  while (true) {
    iter++;
    if (!move(g, iter, 0))
       break;
    if (!move(g, iter, 1))
      break;
    iter++;
    if (!move(g, iter, 2))
      break;
    if (!move(g, iter, 3))
      break;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    solve(n);
  }
  return 0;
}
