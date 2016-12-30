#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int T = (30 * 5) * 2;
bool g[2 * T + 10][2 * T + 10];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int t[100];

int total = 0;
int N;

struct state {
  int x, y, dir, id;
  state(int a, int b, int c, int d) :
    x(a), y(b), dir(c), id(d) {}
  state() {}
};


bool seen[2 * T + 10][2 * T + 10][10][40];

void paint(int x, int y, int dir, int id) {
  if (id == N) return;
  if (seen[x][y][dir][id]) return;
  seen[x][y][dir][id] = true;

  int l = t[id];
  for (int i = 0; i < l; ++i) {
    if (g[x][y] == 0) {
      g[x][y] = 1;
      total++;
    }
    x += dx[dir];
    y += dy[dir];
  }
  x -= dx[dir];
  y -= dy[dir];
  int left = ((dir - 1) + 8) % 8;
  int right = (dir + 1) % 8;
  paint(x + dx[left], y + dy[left], left, id + 1);
  paint(x + dx[right], y + dy[right], right, id + 1);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> t[i];

  paint(T + 1, T + 1, 0, 0);
  cout << total << endl;
  return 0;
}
