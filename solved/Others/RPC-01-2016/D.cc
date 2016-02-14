#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl

int mx[] = {1, 1, 0, -1, -1 ,-1, 0, 1};
int my[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n;

void solve(int x, int y, vector<vector<bool> > &v, vector<vector<char> > &b, int &sol){
  v[x][y] = true;
  for(int i = 0; i < 8; i++){
    int tx = x + mx[i];
    int ty = y + my[i];
    if(tx >= 0 && tx < n && ty >= 0 && ty < n){
      if(b[tx][ty] == '-' && !v[tx][ty]){
        sol++;
        solve(tx, ty, v, b, sol);
      }
    }
  }
}

int main(){
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<char> > board(n, vector<char>(n));
    vector<vector<bool> > vi(n, vector<bool>(n));
    vector<pair<int,int> > ini;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cin >> board[i][j];
        if (board[i][j] == 'w')
          ini.push_back(make_pair(i,j));
      }

    int sol = 0;
    for (int i = 0; i < ini.size(); i++) {
      if(vi[ini[i].first][ini[i].second])
        continue;
      solve(ini[i].first, ini[i].second, vi, board, sol);
    }

    cout << sol << endl;
  }
  return 0;
}
