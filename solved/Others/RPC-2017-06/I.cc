#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

typedef double ld;

struct point {
  ld x, y;
  point() {}
  point(ld a, ld b) : x(a), y(b) {}
  bool operator < (const point &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};


ld dist_point(point a, point b) {
  ld x = a.x - b.x, y = a.y - b.y;
  return x * x + y * y;
}

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n; cin >> n;
  vector<point> all(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> all[i].x >> all[i].y;
  }

  uniform_real_distribution<double> genx(a, c);
  uniform_real_distribution<double> geny(b, d);
  default_random_engine re;

  int max_iter = 20000;
  int hits[] = {0, 0};
  while (max_iter--) {
    point cur(genx(re), geny(re));
    int id = 0;
    for (int i = 0; i < 2 * n; ++i) {
      if (dist_point(all[i], cur) < dist_point(all[id], cur)) {
        id = i;
      }
    }
    hits[id >= n]++;
  }

  puts(hits[0] > hits[1] ? "Gryffindor" : "Slytherin");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
