#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
using namespace std;

const int MN = 60;
char g[MN][MN];
int h, w;

int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, -1, 1, 1};

bool exists(int i, int j) {
  return (i >= 0 and i < h and j >= 0 and j < w);
}

int apsp[MN][MN];
char n = 'b';
void bfs(int s, int sx, int sy) {
  vector<vector<bool>> vis(h, vector<bool>(w, false));
  queue<pair<pair<int,int>,int>> Q;
  
  for (int i = 0; i < n - 'a'; i++)
    apsp[s][i] = -1;
  
  apsp[s][s] = 0;
  vis[sx][sy] = true;
  Q.push(make_pair(make_pair(sx,sy),0));

  while (!Q.empty()) {
    pair<pair<int,int>,int> t = Q.front(); Q.pop();
    int i = t.first.first, j = t.first.second;

    if (g[i][j] >= 'a' and g[i][j] < n)
      apsp[s][g[i][j] - 'a'] = t.second;;
      
    for (int k = 0; k < 4; k++) {
      int nx = i + dx[k], ny = j + dy[k];
      
      if (exists(nx, ny) and !vis[nx][ny] and g[nx][ny] != '#') {
	Q.push(make_pair(make_pair(nx,ny), t.second + 1));
	vis[nx][ny] = true;
      }
    }
  }
  return;
}

int dp[15][(1 << 15)];
int tsp(int i, int mask) {
  if (dp[i][mask] != -1)
    return dp[i][mask];

  if (mask == ((1 << (n - 'a')) - 1))
    return dp[i][mask] = apsp[i][0];

  int ans = 1E9;
  for (int k = 0; k < n - 'a'; k++) {
    if (k == i or mask & (1 << k))
      continue;
    ans = min(ans, apsp[i][k] + tsp(k, mask | (1<< k)));
  }

  return dp[i][mask] = ans;
}

int solve() {
  n = 'a';
  vector<pair<char,pair<int,int> > > loc;
  vector<pair<int,int>> enemies;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> g[i][j];
      if (g[i][j] == '*')
	enemies.push_back(make_pair(i,j));
      if (g[i][j] == '~')
	g[i][j] = '#';
      if (g[i][j] == '@') {
	g[i][j] = 'a';
	loc.push_back(make_pair('a', make_pair(i,j)));
      }
      if (g[i][j] == '!') {
	g[i][j] = ++n;
	loc.push_back(make_pair(n, make_pair(i,j)));
      }
    }
  }
  n++;

  for (auto& e : enemies) {
    int i = e.first, j = e.second;
    for (int k = 0; k < 8; k++) {
      int nx = i + dx[k], ny = j + dy[k];
      if (exists(nx, ny) && g[nx][ny] != '*') {
	if (g[nx][ny] >= 'a' and g[nx][ny] < n)
	  return -1;
	g[nx][ny] = '#';
      }
    }
  }
  
  for (int i = 0; i < loc.size(); i++) 
    bfs(loc[i].first - 'a', loc[i].second.first, loc[i].second.second);
  
  for (int i = 0; i < (n - 'a'); i++)
    if (apsp[0][i] == -1)
      return -1;

  for (int i = 0; i < n - 'a'; i++)
    for (int j = 0; j < (1 << (n - 'a')); j++)
      dp[i][j] = -1;
  
  return tsp(0, 1);
}

int main() {
  while (cin >> h >> w and h + w) {
    cout << solve() << endl;
  }
  
  return 0;
}
