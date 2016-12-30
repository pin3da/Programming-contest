#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int T = (30 * 6);
const int MN = T * T;

bool g[2 * T + 10][2 * T + 10];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int t[100];

int total = 0;
int N;

clock_t start_time;

struct state {
  int x, y, dir, id;
  state(int a, int b, int c, int d) :
    x(a), y(b), dir(c), id(d) {}
  state() {}
};

void paint(int _x, int _y, int _dir, int _id) {
  deque<state> q;
  q.push_back(state(_x, _y, _dir, _id));
  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int dir = q.front().dir;
    int id = q.front().id;
    q.pop_front();

    if (total >= MN) return;
    // if (clock() - start_time > 2 * CLOCKS_PER_SEC) return;
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
    if (id + 1 < N && q.size() < 150 * MN) {
      q.push_back(state(x + dx[left], y + dy[left], left, id + 1));
      q.push_back(state(x + dx[right], y + dy[right], right, id + 1));
    }
  }
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
  start_time = clock();
  cout << total << endl;

  /*
     for (int i = 0; i < 2 * T; ++i) {
     for (int j = 0; j < 2 * T; ++j) {
     cout << g[i][j];
     }
     cout << endl;
     }
     */
  return 0;
}
