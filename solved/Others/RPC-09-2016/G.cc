#include<bits/stdc++.h>
using namespace std;

const int MN = 105;
int board[MN][MN], memo[MN][MN];


int main() {
  int t, nc = 0; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    char c;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if((i == 0 && j == 0) || (i + 1 == n && j + 1 == m)){
          cin >> c;
          board[i][j] = 0;
        }else{
          cin >> board[i][j];
        }
      }
    }
    memset(memo, 0, sizeof memo);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i - 1 >= 0) {
          memo[i][j] = max(board[i][j] + memo[i - 1][j], memo[i][j]);
        }
        if(j - 1 >= 0) {
          memo[i][j] = max(board[i][j] + memo[i][j - 1], memo[i][j]);
        }
      }
    }
    cout << "Game Board #" << ++nc << ": " << memo[n - 1][m - 1] << endl;

  }
}

