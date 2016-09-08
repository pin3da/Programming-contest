#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MX = 1005;
int board[MX][MX],  precalc[MX][MX];

bool check(int i, int j) {
  return board[i][j] - 1 == board[i - 1][j] && board[i][j] - 1 == board[i][j - 1] && board[i][j] - 2 == board[i - 1][j - 1] ;
}

int checkRC(int n, int m){
  int ret = 0;
  for(int i = 0; i < n; i++) {
    int rett = 1;
    for(int j = 0; j < m; j++){
      while(j + 1 < m && board[i][j] + 1 == board[i][j + 1]){
        j++; rett++;
      }
      ret = max(ret, rett);
      rett = 1;
    }
    ret = max(ret, rett);
  }
  for(int i = 0; i < m; i++) {
    int rett = 1;
    for(int j = 0; j < n; j++){
      while(j + 1 < n && board[j][i] + 1 == board[j + 1][i]){
        j++; rett++;
      }
      ret = max(ret, rett);
      rett = 1;
    }
    ret = max(ret, rett);
  }
  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;

  while(cin >> n >> m) {
    memset(precalc, 0, sizeof precalc);

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> board[i][j];

    for(int i = 1; i < n; i++){
      for(int j = 1; j < m; j++){
        if (check(i, j))
          precalc[i][j] = 1;
      }
    }

    vector<int> sweep(m + 1, 0);
    int ans = checkRC(n, m);

    for(int i = 0; i < n; i++){
      int mmin = 10000;
      int inarow = 0;
      for(int j = 0; j < m; j++){
        if(precalc[i][j]){
          sweep[j]++;
          mmin = min(sweep[j], mmin);
          inarow++;
          ans = max(ans, (inarow + 1) * (mmin + 1));
        }else{
          sweep[j] = 0;
          mmin = 10000;
          inarow = 0;
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
