#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 55;
int gn[MN][MN];
int mex[MN * MN + 10];
char board[MN][MN];


void print_best(int final_state) {
  for (int i = 1; i < MN; ++i) {
    for (int j = 1; j < MN; ++j) {
      if (board[i - 1][j - 1] == '1') {
        for (int i1 = 0; i1 < i; ++i1) {
          for (int j1 = 0; j1 < j; ++j1) {
            int cur = gn[i][j] ^ gn[i1][j1] ^ gn[i][j1] ^ gn[i1][j];
            if (cur == final_state) {
              cout << i << ' ' << j << endl;
              cout << i1 << ' ' << j1 << endl;
              return;
            }
          }
        }
      }
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #define endl '\n'
  freopen("coins.in", "r", stdin);
  freopen("coins.out", "w", stdout);
#endif

  for (int i = 1; i < MN; ++i) {
    for (int j = 1; j < MN; ++j) {
      memset(mex, 0, sizeof mex);
      for (int i1 = 0; i1 < i; ++i1) {
        for (int j1 = 0; j1 < j; ++j1) {
          int cur = gn[i1][j1] ^ gn[i][j1] ^ gn[i1][j];
          if (cur <= MN * MN)
            mex[cur] = true;
        }
      }

      for (int k = 0; k < MN * MN + 10; ++k)
        if (mex[k] == 0) {
          gn[i][j] = k;
          break;
        }
    }
  }


  int n, m;
  while (cin >> n >> m) {
    int win = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> board[i][j];
        if (board[i][j] == '1')
          win ^= gn[i + 1][j + 1];
      }
    }

    if (win) {
      cout << "Ann" << endl;
      print_best(win);
    } else {
      cout << "Betty" << endl;
    }
  }
  return 0;
}
