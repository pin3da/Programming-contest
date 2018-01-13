#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y)    {}
  point operator + (const point &p)  const { return point(x+p.x, y+p.y); }
  point operator - (const point &p)  const { return point(x-p.x, y-p.y); }
  point operator * (double c)     const { return point(x*c,   y*c  ); }
  point operator / (double c)     const { return point(x/c,   y/c  ); }
};

double dot(point p, point q)     { return p.x*q.x+p.y*q.y; }
double dist2(point p, point q)   { return dot(p-q,p-q); }
double dist(point p, point q) {
  return sqrt(dist2(p, q));
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc;
  cin >> tc;
  while (tc--) {
    double r;
    int n;
    cin >> r >> n;
    vector<point> all(n);
    for (int i = 0; i < n; i++) {
      cin >> all[i].x >> all[i].y;
    }

    double perimeter = 0;
    for (int i = 0; i < n; i++) {
      perimeter += dist(all[i], all[(i + 1) % n]);
    }

    double ans = (perimeter - 2 * acos(-1) * r) / perimeter;
    if (ans < 0) {
      cout << "Not possible" << endl;
    } else {
      cout << fixed << setprecision(10) << ans << endl;
    }
  }
  return 0;
}
