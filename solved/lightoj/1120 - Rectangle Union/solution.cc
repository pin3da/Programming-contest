#include <bits/stdc++.h>

using namespace std;

struct event {
  int x, type, y1, y2;
  event() {}
  event(int a, int b, int c, int d) : x(a), type(b), y1(c), y2(d) {}

  bool operator < (const event &o) const {
    if (x == o.x) {
      if (type == o.type) {
        if (y1 == o.y1)
          return y2 < o.y2;
        return y1 < o.y1;
      }
      return type < o.type;
    }
    return x < o.x;
  }
};

void solve() {
  int n;
  scanf("%d", &n);

  vector<event> sl;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    sl.push_back(event(x1, 0, y1, y2));
    sl.push_back(event(x2, 1, y1, y2));
  }
  sort(sl.begin(), sl.end());
  multiset<int> points;

  int last_x = -1;
  long long area = 0;
  for (int i = 0; i < (int)sl.size(); i++) {
    event &cur = sl[i];
    if (last_x != -1) {
      long long mmax = *(--points.end());
      long long mmin = *points.begin();
      long long delta_x = cur.x - last_x;
      long long delta_y = mmax - mmin;
      area += delta_x * delta_y;
    }
    if (cur.type == 0) {
      points.insert(cur.y1);
      points.insert(cur.y2);
    } else {
      points.erase(points.find(cur.y1));
      points.erase(points.find(cur.y2));
    }

    last_x = cur.x;
  }
  printf("%lld\n", area);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; i++) {
    printf("Case %d: ", i);
    solve();
  }
  return 0;
}
