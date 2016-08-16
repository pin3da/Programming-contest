#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int mod = 5318008;

const int MN = 5005;
int d[2][MN];
int r[MN][2];

int X, Y, N;

int add(int x, int y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

int fill_dist(int a, int b) {

  int stx = 0, sty = 0;
  memset(d, 0, sizeof d);
  memset(r, 0, sizeof r);

  d[stx][Y] = r[X][sty] = 1;
  for (int x = X + 1; x <= a; ++x, stx ^= 1) {
    for (int i = 1; i <= N; ++i)
      d[stx ^ 1][i] =
        add(add(d[stx][i - 1], d[stx][i]), d[stx][i + 1]);
  }

  for (int y = Y + 1; y <= b; ++y, sty ^= 1) {
    for (int i = 1; i <= N; ++i)
      r[i][sty ^ 1] =
        add(add(r[i - 1][sty], r[i][sty]), r[i + 1][sty]);
  }

  return d[stx][b] + r[a][sty];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> N;
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int dx = abs(x - a), dy = abs(y - b);
    if (dx == dy) {
      cout << 1 << endl;
      continue;
    }
    if (x > a) {
      swap(x, a);
      swap(y, b);
    }

    if (y > b) {
      y = N - y + 1;
      b = N - b + 1;
    }
    X = x, Y = y;
    cout << fill_dist(a, b) << endl;
  }
  return 0;
}
