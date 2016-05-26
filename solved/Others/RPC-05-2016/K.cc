#include<bits/stdc++.h>
using namespace std;

bool check(int n, vector<vector<int> > &board) {
  for(int i = 0; i < n; i++) {
    vector<bool> seen(n);
    for(int j = 0; j < n; j++) {
      if(seen[board[i][j]]) return false;
      seen[board[i][j]] = true;
    }
  }

  for(int i = 0; i < n; i++) {
    vector<bool> seen(n);
    for(int j = 0; j < n; j++) {
      if(seen[board[j][i]]) return false;
      seen[board[j][i]] = true;
    }
  }

  return true;
}

bool checkSquare(int x, int y, int sq, vector<vector<int> > &board) {
  vector<bool> seen(board.size());
  for(int i = 0; i < sq; i++) {

    for(int j = 0; j < sq; j++){
      if(seen[board[i + x][j + y]]) return false;
      seen[board[i + x][j + y]] = true;
    }
  }

  return true;
}

int main() {
  int n, t; cin >> t;
  while(t--) {
    cin >> n;
    int sq = sqrt(n);
    vector<vector<int> > board(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> board[i][j];
      }
    }

    bool ok = check(n, board);
    for(int i = 0; i < sq; i++) {
      for(int j = 0; j < sq; j++) {
        if(!checkSquare(i * sq, j * sq, sq, board)){
          ok = false;
        }
      }
    }

    if(ok){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
}
