using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct state {
  int x, y, cost;
  char need;
  state (int a, int b, char c, int d) : x(a), y(b), need(c), cost(d) {}
  state () {}
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool visited[22][22][33];

void solve() {
  int n;
  int x, y;
  char last = 'A';
  cin >> n;
  vector<vector<char> > g(n, vector<char> (n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'A') {
        x = i;
        y = j;
      }
      last = max(last, g[i][j]);
    }

  last++;

  deque<state> q;
  q.push_back(state(x, y, 'A', 0));

  memset(visited, 0, sizeof visited);

  while (!q.empty()) {
    state cur = q.front();
    q.pop_front();
    x = cur.x;
    y = cur.y;
    char need = cur.need;
    int cost = cur.cost;
    if (visited[x][y][need - 'A'])
      continue;

    visited[x][y][need - 'A'] = true;

    if (g[x][y] == need)
      need++;

    if (need == last) {
      printf("%d\n", cost);
      return;
    }


    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
          ( g[nx][ny] == '.' || (g[nx][ny] >= 'A' && g[nx][ny] <= need))) {
        q.push_back(state(nx, ny, need, cost + 1));
      }
    }
  }
  puts("Impossible");
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
