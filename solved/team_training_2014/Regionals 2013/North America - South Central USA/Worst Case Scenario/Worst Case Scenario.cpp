using namespace std;
#include<bits/stdc++.h>

const int MN = 111;
char grid[MN][MN];
int node[MN][MN];
int visited[MN][MN];
pair<int, int> parent[MN][MN];
int n, m;
int cur;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void propagate(int a, int b) {
  queue<pair<int, int> > q;
  q.push(make_pair(a, b));

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (grid[x][y] == 'X') continue;

    if (grid[x][y] == 'D') {
      if (visited[x][y]) continue;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
          q.push(make_pair(nx, ny));
        }
      }
      visited[x][y] = true;
    } else {
      grid[x][y]++;
    }
  }
}

void solve() {
  cin>>m>>n;
  cur = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin>>grid[i][j];


  int q;cin>>q;
  while (q--) {
    int x, y;
    cin>>y>>x;
    memset(visited, 0, sizeof visited);
    propagate(x, y);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cout<<grid[i][j];
    cout<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;cin>>tc;
  for (int i = 0;i < tc; ++i)
    solve();
  return 0;
}
