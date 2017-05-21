#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  double x, y;
  point() {}
  point(double a, double b) : x(a), y(b) {}
};

bool colinear(const point &p, const point &q, const point &r) {
    double ax = q.x - p.x;
    double ay = q.y - p.y;
    double bx = r.x - p.x;
    double by = r.y - p.y;
    double d = ax*by - bx*ay;
    if (cmp(d, 0) == 0) return true;
    return false;
}

point find_center_2(const point &p, const point&q) {
  point center(p.x + q.x, p.y + q.y);
  center.x *= 0.5;
  center.y *= 0.5;
  return center;
}

point find_center(const point &p, const point &q, const point &r) {
    double ax = q.x - p.x;
    double ay = q.y - p.y;
    double bx = r.x - p.x;
    double by = r.y - p.y;
    double d = ax*by - bx*ay;

    double cx = (q.x + p.x) / 2;
    double cy = (q.y + p.y) / 2;
    double dx = (r.x + p.x) / 2;
    double dy = (r.y + p.y) / 2;

    double t1 = bx*dx + by*dy;
    double t2 = ax*cx + ay*cy;

    double x = (by*t2 - ay*t1) / d;
    double y = (ax*t1 - bx*t2) / d;

    return point(x, y);
}

double dist(point a, point b) {
  double x = a.x - b.x, y = a.y - b.y;
  return sqrt(x * x + y * y);

}

bool check(point center, double r, vector<point> &red,
           vector<point> &blue) {

  int red_inside = true;
  int blue_outside = true;
  for (auto it: blue) {
    // strictly inside
    if (cmp(dist(center, it), r) == -1) blue_outside = false;
  }
  for (auto it: red) {
    // strictly outside
    if (cmp(dist(center, it), r) == 1) red_inside = false;
  }
  return red_inside && blue_outside;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<point> red, blue, all;
  for (int i = 0; i < n; ++i) {
    point p; cin >> p.x >> p.y;
    char type; cin >> type;
    all.push_back(p);
    if (type == 'I')
      red.push_back(p);
    else
      blue.push_back(p);
  }

  if ((red.size() <= 1) || (n <= 2)) {
    puts("No");
  } else {
    int len = all.size();
    int possible = 0;
    int test = 0;
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        test++;
        point center_2 = find_center_2(all[i], all[j]);
        if (check(center_2, dist(center_2, all[i]), red, blue))
          possible++;
        for (int k = j + 1; k < len; ++k) {
          if (colinear(all[i], all[j], all[k])) {
            // case 2 points
          } else {
            point center = find_center(all[i], all[j], all[k]);
            if (check(center, dist(center, all[i]), red, blue))
              possible++;
          }
        }
      }
    }
    puts(possible == 0? "Yes" : "No");
  }
  return 0;
}
