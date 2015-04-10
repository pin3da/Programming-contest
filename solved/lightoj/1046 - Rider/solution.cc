using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct rider{
  int x, y, k;
  rider() {}
  rider(int a, int b, int c) : x(a), y(b), k(c) {}
};

const int inf = 1 << 30;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

typedef vector<vector<int> > board;

void bfs(board &dist, board &riders, int k, int x, int y) {
  int n = dist.size(), m = dist[0].size();
  vector<vector<bool> > seen(n, vector<bool>(m, false));

  deque<rider> q;
  q.push_back(rider(x, y, 0));

  while (!q.empty()) {
    rider cur = q.front();
    q.pop_front();

    if (seen[cur.x][cur.y])
      continue;

    seen[cur.x][cur.y] = true;

    int mv = (cur.k + k - 1) / k;
    dist[cur.x][cur.y] += mv;
    riders[cur.x][cur.y]++;

    for (int i = 0; i < 8; ++i) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if ( nx >= 0 && nx < n && ny >= 0 && ny < m  && !seen[nx][ny])
        q.push_back(rider(nx, ny, cur.k + 1));
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  char t;
  int total = 0;
  board dist(n, vector<int>(m, 0));
  board riders(n, vector<int>(m, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> t;
      if (t != '.') {
        total++;
        bfs(dist, riders, t - '0', i, j);
      }
    }
  }

  int best = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (riders[i][j] == total && dist[i][j] < best)
        best = dist[i][j];
    }
  }

  if (best != inf)
    printf("%d\n", best);
  else
    printf("-1\n");
}

int main () {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
