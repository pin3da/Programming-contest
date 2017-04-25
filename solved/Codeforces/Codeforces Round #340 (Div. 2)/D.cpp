// http://codeforces.com/contest/617/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
struct point{
  int x, y, dir, cost, seen;
  point() {}
  point(int a, int b, int c, int d, int e) :
    x(a), y(b), dir(c), cost(d), seen(e) {}
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int op[] = {2, 3, 0, 1};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<point> p(3);
  map<int, int> idx, idy;
  vector<vector<int>> pos(3, vector<int>(3, 0));
  vector<int> x, y;
  for (auto &i : p) {
    cin >> i.x >> i.y;
    x.push_back(i.x);
    y.push_back(i.y);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  y.resize(unique(y.begin(), y.end()) - y.begin());

  for (auto &i : p) {
    for (int j = 0; j < x.size(); ++j)
      if (i.x == x[j])
        i.x = j;
    for (int j = 0; j < y.size(); ++j)
      if (i.y == y[j])
        i.y = j;

    // D(i.x);D(i.y);
    pos[i.x][i.y] = 1;
  }

  int ans = 100;
  for (auto &kkk : p) {
    point cur = kkk;
    cur.dir = -1;
    cur.cost = 0;
    cur.seen = 1;
    queue<point> q;
    q.push(cur);
    while (!q.empty()) {
      point node = q.front();q.pop();
      if (node.cost > 4) continue;
      if (node.seen == 3) {
        ans = min(ans, node.cost);
        continue;
      }
      for (int i = 0; i < 4; ++i) {
        int nx = node.x + dx[i];
        int ny = node.y + dy[i];
        if (nx >= 0 && nx < x.size() && ny >= 0 && ny < y.size() &&
            (node.dir < 0 || i != op[node.dir])) {
          point to(nx, ny, i, node.cost + (i != node.dir), node.seen + pos[nx][ny]);
          q.push(to);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
