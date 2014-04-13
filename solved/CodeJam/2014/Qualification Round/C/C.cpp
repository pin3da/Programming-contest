using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

int r,c,m, n;
unsigned int popcnt_next(unsigned int n) {
  unsigned int c = (n & -n);
  unsigned int r = n+c;
  return (((r ^ n) >> 2) / c) | r;
}

int dx [] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy [] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void solve() {

  unsigned int mask = (1<<m) - 1;
  unsigned int tope = (1<<(r*c));

  char mat[r][c];

  while (mask < tope ) {

    int ini_y = 0, ini_x = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int index = i * c + j;
        if ((mask>>index)  & 1)
          mat[i][j] = '*';
        else {
          mat[i][j] = '.';
          ini_x = i;
          ini_y = j;
        }
      }
    }

    queue<pair<int,int> > q;
    q.push(make_pair(ini_x, ini_y));

    vector<vector<int> > visited(r, vector<int>(c, 0));

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;q.pop();
      visited[x][y] = true;

      int count = 0;
      for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < r and ny >= 0 and ny < c)
          if (mat[nx][ny] == '*') count++;
      }

      if (count == 0) {
        for (int i = 0; i < 8; ++i) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          if (nx >= 0 and nx < r and ny >= 0 and ny < c and mat[nx][ny] != '*' and !visited[nx][ny])
            q.push(make_pair(nx, ny));
        }
      }
    }

    int valid = 1;
    for (int i = 0; i < r and valid; ++i) {
      for (int j = 0; j < c and valid ; ++j) {
        if (mat[i][j] == '.' and !visited[i][j]) valid = 0;
      }
    }

    if (valid) {
      mat[ini_x][ini_y] = 'c';
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
          cout<<mat[i][j];
        cout<<endl;
      }
      return;
    }
    mask = popcnt_next(mask);
  }

  cout<<"Impossible"<<endl;


}

int main() {

  int tc;cin>>tc;
  for (int tid = 0; tid < tc; ++tid) {
    cin>>r>>c>>m;
    cout<<"Case #"<<(tid+1)<<":"<<endl;
    solve();
  }

  return 0;
}
