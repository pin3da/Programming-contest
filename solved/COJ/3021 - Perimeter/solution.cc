#include<bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x << " = " << x << endl
using namespace std;

const int MX = 105;

char board[MX][MX];
bool vi[MX][MX];
int ans;
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, -1, 1};

void solve(int x, int y) {
  vi[x][y] = true;
  for(int i = 0; i < 4; i++) {
    int xt = x + mx[i];
    int yt = y + my[i];
    if(xt < 0 || xt >= MX || yt < 0  || yt >= MX || vi[xt][yt]) continue;
    if(board[xt][yt] == 'H') solve(xt, yt);
    if(board[xt][yt] == 'B') ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int  n,x,y;
  while(cin >> n) {
    for(int i = 0; i < MX; i++) {
      for(int j = 0; j < MX; j++) {
        board[i][j] = 'H';
        vi[i][j] = false;
      }
    }

    for(int i = 0; i < n; i++) {
      cin >> x >> y;
      board[x][y] = 'B';
    }

    ans = 0;
    solve(0, 0);
    cout << ans << endl;
  }
  return 0;
}
