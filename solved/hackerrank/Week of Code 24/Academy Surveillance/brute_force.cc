#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef vector<vector<int> > board;

bool valid(board &cur) {
  int a = cur.size(),
      b = cur[0].size();
  for (int i = 0; i + 2 < a; ++i) {
    for (int j = 0; j + 2 < b; ++j) {
      int c = 0;
      for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y)
          if (cur[i + x][j + y]) c++;

      if (c != 2)
        return false;
    }
  }
  return true;
}

void print_board(board &cur) {
  int a = cur.size();
  int b = cur[0].size();
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j)
      cout << cur[i][j];
    cout << endl;
  }
  cout << endl;
}
int main() {

  int tc; cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    int top = a * b;
    int ans = 0;
    for (int m = 0; m < (1 << top); ++m) {
      board cur(a, vector<int> (b));
      for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
          int id = i * b + j;
          if ((m >> id) & 1)
            cur[i][j] = 1;
        }
      }
      if (valid(cur)) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
