#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-15;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const double top = 2.0 * sqrt(0.5);
const double pi = acos(-1);

struct point {
  double x, y, z;
  point(double a, double b, double c) : x(a), y(b), z(c) {}
  // WARNING: this operator is for the 2d projection.
  bool operator<(const point &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

double norm(point p) {
  return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

point rotate_x(point p, double theta) {
  point ans = p;
  ans.y = p.y * cos(theta) - p.z * sin(theta);
  ans.z = p.y * sin(theta) + p.z * cos(theta);
  return ans;
}

point rotate_y(point p, double theta) {
  point ans = p;
  ans.x = p.x * cos(theta) + p.z * sin(theta);
  ans.z = p.z * cos(theta) - p.x * sin(theta);
  return ans;
}

vector<point> rotate(vector<point> p, double dx, double dy) {
  int n = p.size();
  for (int i = 0; i < n; i++) {
    p[i] = rotate_x(rotate_y(p[i], dy), dx);
  }
  return p;
}

// 2D FUNCTIONS!
double cross(point p, point q) { return p.x*q.y-p.y*q.x; }
double area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

vector<point> convex_hull(vector<point> pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<point> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  return pts;
}

double area_2d(vector<point> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(area / 2.0);
}

void solve() {
  double area; cin >> area;
  vector<point> cube;
  cube.emplace_back(-0.5, -0.5, -0.5);
  cube.emplace_back(-0.5, 0.5, -0.5);
  cube.emplace_back(0.5, -0.5, -0.5);
  cube.emplace_back(0.5, 0.5, -0.5);
  cube.emplace_back(-0.5, -0.5, 0.5);
  cube.emplace_back(-0.5, 0.5, 0.5);
  cube.emplace_back(0.5, -0.5, 0.5);
  cube.emplace_back(0.5, 0.5, 0.5);
  double del_x = 0, del_y = 0;
  if (cmp(area, top) != 1) {
    double lo = 0, hi = pi / 4.0;
    int iter = 100000;
    while ((cmp(lo, hi) == -1) && iter--) {
      double alpha = (lo + hi) * 0.5;
      vector<point> cur = rotate(cube, alpha, 0);
      cur = convex_hull(cur);
      double a = area_2d(cur);
      if (cmp(a, area) == -1)
        lo = alpha;
      else if (cmp(a, area) == 1)
        hi = alpha;
      else
        break;
    }
    del_x = lo;
  } else {
    del_x = pi / 4.0;
    double lo = 0, hi = pi / 4.0;
    int iter = 100000;
    while ((cmp(lo, hi) == -1) && iter--) {
      double alpha = (lo + hi) * 0.5;
      vector<point> cur = rotate(cube, del_x, alpha);
      cur = convex_hull(cur);
      double a = area_2d(cur);
      if (cmp(a, area) == -1)
        lo = alpha;
      else if (cmp(a, area) == 1)
        hi = alpha;
      else
        break;
    }
    del_y = lo;
  }

  vector<point> ans;
  ans.emplace_back(0.5, 0, 0);
  ans.emplace_back(0, 0.5, 0);
  ans.emplace_back(0, 0, 0.5);

  cout << fixed << setprecision(8);

  for (int i = 0; i < 3; i++) {
    ans[i] = rotate_x(rotate_y(ans[i], del_y), del_x);
    cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
  }
}

int main() {
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ":\n";
    solve();
  }
  return 0;
}
