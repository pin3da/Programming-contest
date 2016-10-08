#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct point {
  int x, y;
  point() {}
  point (int a, int b) : x(a), y(b) {}
};

const int MN = 1e5 + 100;

const int inf = 234567;
point p[MN];

point transform(point p) {
  return point(p.x + p.y, p.y - p.x);
}


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #define endl '\n'
#endif

  int n, m, k;
  while (cin >> n >> m >> k) {
    for (int i = 0; i < k; ++i) {
      cin >> p[i].x >> p[i].y;
      p[i] = transform(p[i]);
    }
    vector<point> b;
    for (int i = 0; i <= n; ++i) {
      b.push_back(point(i, 0));
      b.push_back(point(i, m));
    }
    for (int i = 0; i <= m; ++i) {
      b.push_back(point(0, i));
      b.push_back(point(n, i));
    }

    map<int, set<int> > x, y;
    for (int i = 0; i < (int)b.size(); ++i) {
      b[i] = transform(b[i]);
      x[b[i].x].insert(b[i].y);
      y[b[i].y].insert(b[i].x);
      cout << b[i].x << ' ' << b[i].y << endl;
    }

    for (map<int, set<int> >::iterator it = x.begin(); it != x.end(); ++it) {
      it->second.insert(-inf);
      it->second.insert(+inf);
    }

    for (map<int, set<int> >::iterator it = y.begin(); it != y.end(); ++it) {
      it->second.insert(-inf);
      it->second.insert(+inf);
    }

    for (set<int>::iterator it = y[0].begin(); it != y[0].end(); ++it)
      debug(*it);
  }

  return 0;
}
