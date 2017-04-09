#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> board;

void asdf(board &b, int y, int d) {
  int n = b.size();
  for (int i = 0; i < n; ++i)
    b[0][i] = '+';

  for (int i = 0; i < n; ++i) {
    if (i == 0)
      b[i][y] = 'o';
    else
      b[i][y] = 'x';
    y = (y + d + n) % n;
  }

  for (int i = 1; i < n - 1; ++i) {
    if (b[n - 1][i] == '.')
      b[n - 1][i] = '+';
  }
}

struct entry {
  char c;
  int x, y;
  entry() {}
  entry (char a, int b, int w) : c(a), x(b), y(w) {}
};

void print(board b, int y, int d) {
  int n = b.size();
  board ori = b;
  asdf(b, y, d);
  vector<entry> ans;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] != ori[i][j])
        ans.emplace_back(b[i][j], i + 1, j + 1);
      if (b[i][j] == '+') sum += 1;
      if (b[i][j] == 'x') sum += 1;
      if (b[i][j] == 'o') sum += 2;
    }
  }
  printf("%d %d\n", sum, (int)ans.size());
  for (auto i : ans) {
    printf("%c %d %d\n", i.c, i.x, i.y);
  }
}

int fill_b(board b, int y, int d) {
  int n = b.size();
  asdf(b, y, d);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == '+') ans += 1;
      if (b[i][j] == 'x') ans += 1;
      if (b[i][j] == 'o') ans += 2;
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<char>> b(n, vector<char>(n, '.'));
  for (int i = 0; i < m; ++i)  {
    char c;
    int x, y;
    cin >> c >> x >> y;
    x--;y--;
    b[x][y] = c;
  }

  for (int i = 0; i < n; ++i) {
    if (b[0][i]) {
      int b1 = fill_b(b, i, 1);
      int b2 = fill_b(b, i, -1);
      if (b1 > b2) {
        print(b, i, 1);
      } else {
        print(b, i, -1);
      }
      return;
    }
  }
  print(b, 0, 1);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
