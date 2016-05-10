#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int m, n;
int valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> m >> n) {
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> g[i][j];

    int x = 0, y = 0;
    while (valid(x, y) && g[x][y] != '*' && g[x][y] != 'X') {
      char op = g[x][y];
      g[x][y] = 'X';
      if (op == '^') {
        x--;
        while (valid(x, y) && g[x][y] == '.')
          x--;
      }
      if (op == '>') {
        y++;
        while (valid(x, y) && g[x][y] == '.')
          y++;
      }
      if (op == '<') {
        y--;
        while (valid(x, y) && g[x][y] == '.')
          y--;
      }
      if (op == 'v') {
        x++;
        while (valid(x, y) && g[x][y] == '.')
          x++;
      }
    }

    if (valid(x, y) && g[x][y] == '*')
      cout << "*" << endl;
    else
      cout << "!" << endl;

  }

  return 0;
}
