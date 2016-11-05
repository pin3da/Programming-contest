#include<bits/stdc++.h>
using namespace std;
const int MX = 1005;
const int inf = 10000000;

char board[MX][MX];
int fire[MX][MX], man[MX][MX], n, m;
bool v[MX][MX];

struct state{
  int x, y, t;
  state(){}
  state(int _x, int _y, int _t): x(_x), y(_y), t(_t){}

};

int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

bool check_fire(int x, int y) {
  if(x >= 0 && x < n && y  >= 0 && y < m && board[x][y] != '#' && fire[x][y] == inf)
    return true;
  return false;
}

void BFS_fire(vector<state> &f) {
  queue<state> Q;
  for(int i = 0; i < f.size(); i++){
    Q.push(f[i]);
    fire[f[i].x][f[i].y] = 1;
  }

  while(!Q.empty()) {
    state tm = Q.front(); Q.pop();
    for(int i = 0; i < 4; i++) {
      int tx = tm.x + mx[i];
      int ty = tm.y + my[i];
      if(check_fire(tx, ty)) {
        fire[tx][ty] = tm.t + 1;
        Q.push(state(tx, ty, tm.t + 1));
      }
    }
  }
}

bool check(int x, int y, int t) {
  if(x >= 0 && x < n && y  >= 0 && y < m && board[x][y] != '#' &&  t < fire[x][y] && !v[x][y])
    return true;
  return false;
}

bool BFS(state &s, state &e) {
  queue<state> Q;
  Q.push(s);
  v[s.x][s.y] = true;


  while(!Q.empty()) {
    state tm = Q.front(); Q.pop();
    if(tm.x == e.x && tm.y == e.y) {
      return true;
    }
    for(int i = 0; i < 4; i++) {
      int tx = tm.x + mx[i];
      int ty = tm.y + my[i];
      if(check(tx, ty, tm.t + 1)) {
        v[tx][ty] = true;
        Q.push(state(tx, ty, tm.t + 1));
      }
    }
  }
  return false;
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n >> m;
    vector<state> ff;
    state st, en;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> board[i][j];
        if(board[i][j] == 'F') ff.push_back(state(i, j, 1));
        if(board[i][j] == 'S') {st.x = i; st.y = j; st.t = 1;}
        if(board[i][j] == 'E') {en.x = i; en.y = j;}
        fire[i][j] = inf;
        v[i][j] = false;
      }
    }
    BFS_fire(ff);
    /*
       for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) cout << v[i][j] << " ";
       cout << endl;
       }
       */
    cout << (BFS(st, en) ? "Y" : "N") << endl;
  }
  return 0;
}
