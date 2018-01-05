#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

struct point {
  int x, y;
  long long frec;
  point(int a, int b, long long c) : x(a), y(b), frec(c) {}

  bool operator<(const point &o) const {
    if (frec == o.frec)
      return make_pair(x, y) < make_pair(o.x, o.y);
    return frec < o.frec;
  }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct board {
  int n, m, r;
  board(int a, int b, int c = 1) : n(a), m(b), r(c) {}

  long long frec(int x, int y) {
    long long a = min(x, n - r) - max(x - r + 1, 0) + 1;
    long long b = min(y, m - r) - max(y - r + 1, 0) + 1;
    return a * b;
  }

  bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  cout << fixed << setprecision(10);

  long long n, m, r, k;
  cin >> n >> m >> r >> k;

  board b(n, m, r);
  double total = (n - r + 1) * (m - r + 1);

  priority_queue<point> q;
  int x = n / 2, y = m / 2;
  point start(x, y, b.frec(x, y));
  set<point> seen;
  seen.insert(start);
  q.push(start);

  double ans = 0;

  while (k--) {
    point cur = q.top(); q.pop();
    ans += cur.frec / total;

    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (b.valid(nx, ny)) {
        point next(nx, ny, b.frec(nx, ny));
        if (seen.count(next) == 0) {
          seen.insert(next);
          q.push(next);
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
