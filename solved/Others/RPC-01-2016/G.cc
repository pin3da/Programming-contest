#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'
#define x first
#define y second
int n, m;
typedef pair<int,int> pos;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char mov[] = {'E', 'S', 'W', 'N'};
const pair<pos,pos> inf = {{-1, -1}, {-1, -1}};



struct state{
  int x,y,w,z,p;
  char s;
  state(){}
  state(int _x, int _y, int _w, int _z, int _p
      , char _s){
    x = _x;
    y = _y;
    w = _w;
    z = _z;
    p = _p;
    s = _s;
  }

  bool operator < (const state &a) const {
    pair<pos,pos> g = {{x,y}, {w,z}};
    pair<pos,pos> h = {{a.x,a.y}, {a.w,a.z}};
    return g < h;
  }
};


void print_t(state &tm) {
  cout << tm.x << " " << tm.y << " " << tm.w << " " << tm.z << " " << tm.p << " " << tm.s;
}

string bfs(vector<vector<char> > &g, pos p1, pos p2) {
  map<state, state> vis;
  queue<state> Q;

  Q.push(state(p1.x, p1.y, p2.x, p2.y, 0, '*'));
  vis[Q.front()] = Q.front();
  string ans = "";
  while (!Q.empty()) {
    state tm = Q.front(); Q.pop();

    if(tm.x == tm.w && tm.y == tm.z) {
      state cur = tm;
      int cc = 0;
      while(cur.s != '*'){
        ans.push_back(cur.s);
        cur = vis[cur];
        cc++;
      }
      return ans;
    }

    for(int i = 0; i < 4; i++){
      int tx = (tm.x + dx[i] + n) % n;
      int tw = (tm.w + dx[i] + n) % n;
      int ty = (tm.y + dy[i] + m) % m;
      int tz = (tm.z + dy[i] + m) % m;
      state tmm = state(tx,ty,tw,tz,tm.p + 1, mov[i]);
      if((vis.count(tmm) == 0) and (g[tx][ty] == '.' or g[tw][tz] == '.')){
        if (g[tx][ty] != '.') {
          if (g[tx][ty] != 'X')
            continue;
          tmm.x = tm.x;
          tmm.y = tm.y;
        }
        if (g[tw][tz] != '.') {
          if (g[tw][tz] != 'X')
            continue;
          tmm.w = tm.w;
          tmm.z = tm.z;
        }
        if (vis.count(tmm))
          continue;
        Q.push(tmm);
        assert(vis.count(tmm) == 0);
        vis[tmm] = tm;
      }
    }

  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> m;
    vector<vector<char> > g(n, vector<char>(m));
    vector<pos> pacman;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++){
        cin >> g[i][j];
        if (g[i][j] == 'P') {
          pacman.push_back({i, j});
          g[i][j] = '.';
        }
      }
    }
    string ans = bfs(g, pacman[0], pacman[1]);

    if (ans.size() == 0) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      reverse(ans.begin(), ans.end());
      cout << ans.size() << " " << ans << endl;
    }
  }

  return 0;
}
