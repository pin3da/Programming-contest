#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
#define endl '\n'
char G[MAXN][MAXN][MAXN];
bool V[MAXN][MAXN][MAXN];
int n,m,p;

struct state{
  int x, y, floor;
  state(){}
  state(int _x, int _y, int _f):x(_x), y(_y), floor(_f){}

  bool operator ==(const state &s) const {
    return (s.x == x && y == s.y && floor == s.floor);
  }
};

int mx[] = {1, 0, -1, 0, 0, 0};
int my[] = {0, 1, 0, -1, 0, 0};
int mz[] = {0, 0, 0, 0, 1, -1};

bool check(int x, int y, int z, bool sp) {
  if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= p ||V[z][x][y] || G[z][x][y] == '#') return false;

  if(sp){
    //cout << "spe: " <<  z << " " << x << " " << y <<endl;
    //cout << "char: "<< G[z][x][y] << endl;
    return (G[z][x][y] == '-');
  }
  return true;
}

int solve(state b, state e) {
  queue<pair<state, int> > Q;
  Q.push(make_pair(b, 0));
  while(!Q.empty()) {
    state tn = Q.front().first;
    int dis = Q.front().second;
    //cout << "start "<< tn.floor << " " << tn.x << " " << tn.y << endl;
    V[tn.floor][tn.x][tn.y] = true;
    Q.pop();

    if(tn == e){
      return dis;
    }

    for(int i = 0; i < 4; i++) {
      int tx = tn.x + mx[i];
      int ty = tn.y + my[i];
      int tz = tn.floor + mz[i];
      if(check(tx, ty, tz, 0)){
        //cout << tz << " " << tx << " " << ty << endl;
        V[tz][tx][ty] = true;
        Q.push(make_pair(state(tx, ty, tz), dis + 1));
      }
    }
    if(G[tn.floor][tn.x][tn.y] == '-') {
      //cout << "join" << endl;
      for(int i = 4; i < 6; i++) {
        int tx = tn.x + mx[i];
        int ty = tn.y + my[i];
        int tz = tn.floor + mz[i];

        if(check(tx, ty, tz, 1)){
          V[tz][tx][ty] = true;
          //cout <<"stairs " << tz << " " << tx << " " << ty << endl;
          Q.push(make_pair(state(tx, ty, tz), dis + 1));
        }
      }
    }
    //cout << endl;

  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while(cin >> n >> m >> p && n + m + p) {
    state b,e;

    for(int i = 0; i < p; i++ ) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < m; k++) {
          V[i][j][k] = false;
          cin >> G[i][j][k];
          if(G[i][j][k] == 'E') {
            e = state(j, k, i);
            G[i][j][k] = '.';
          }
          if(G[i][j][k] == 'S') {
            b = state(j, k, i);
            G[i][j][k] = '.';
          }
        }
      }
    }
    int ans = solve(b,e);
    cout << ans << endl;
  }
}
