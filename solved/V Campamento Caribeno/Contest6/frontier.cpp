using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

struct point {
  int x, y;
  point() {}
  point(int a, int b) : x(a) , y(b) {}

  double dist(point o) {
    double a = x - o.x;
    double b = y - o.y;
    return sqrt(a*a + b*b);
  }
};

vector<point> frontier;
vector<point> monuments;

int n, m;

const double inf = 1e100;

const int MN = 55;

int _fun[MN][MN];

int fun(int i, int j) {
  if (_fun[i][j] != -1) return _fun[i][j];
  point base(frontier[j].x - frontier[i].x, frontier[j].y - frontier[i].y);

  for (int k = 0; k < monuments.size(); ++k) {
    int cross = base.x * monuments[k].y - base.y * monuments[k].x;
    if (cross <= 0) return _fun[i][j] = 0;
  }
  return _fun[i][j] = 1;
}

double _dp[MN][MN][MN];

double dp(int ini, int cur, int from, int used) {

  if (_dp[ini][cur][from] > 0) return _dp[ini][cur][from];

  if (ini == cur) {
    if (used < 1) return inf;
    if (fun(from, cur))
      return _dp[ini][cur][from] = frontier[cur].dist(frontier[from]);
    else
      return _dp[ini][cur][from] = inf;
  }

  double ans = inf;
  if (fun(from, cur))
    ans = dp(ini, cur + 1, cur, (used < 2) ? used + 1 : used) + frontier[cur].dist(frontier[from]);

  ans = min(ans , dp(ini, cur + 1, from, used));

  return _dp[ini][cur][from] = ans;
}

int main() {
  cin>>n>>m;
  frontier.resize(n);
  monuments.resize(m);
  memset(_fun, -1, sizeof _fun);

  for (int i = 0; i < MN; ++i) for (int j = 0; j < MN; ++j) for (int k = 0; k < MN; ++k) _dp[i][j][k] = -1;
  for (int i = 0; i < n; ++i)
    cin>>frontier[i].x>>frontier[i].y;

  for (int i = 0; i < m; ++i)
    cin>>monuments[i].x>>monuments[i].y;


  double ans = inf;

  for (int i = 0; i < n; ++i) {
    ans = min(ans, dp(i, (i + 1) % n, i, 0));
  }

  cout<<ans<<endl;

  return 0;
}
