using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

int cmp(double x, double y = 0, double tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


bool segment_line_intersection(double x0, double y0,
    double x1, double y1, double x2, double y2,
    double x3, double y3, double &x, double &y){

  double t0 = (y3-y2)*(x0-x2) - (x3-x2)*(y0-y2);
  double t1 = (x1-x0)*(y2-y0) - (y1-y0)*(x2-x0);
  double det =(y1-y0)*(x3-x2) - (y3-y2)*(x1-x0);

  if (fabs(det) < EPS){
    return false;
  }else{
    t0 /= det;
    t1 /= det;
    if (cmp(0, t0) <= 0 and cmp(t0, 1) < 0){
      x = x0 + t0 * (x1-x0);
      y = y0 + t0 * (y1-y0);
      return true;
    }
    return false;
  }
}

vector<PT> cut(vector<PT> &p, double x0, double y0, double x1, double y1) {
  int hits = 0, side = 0;
  double x, y;
  vector<vector<PT> > ans(2);

  for (int i = 0; i < p.size(); ++i) {
    int j = (i + 1) % p.size();
    if (segment_line_intersection(p[i].x, p[i].y,
          p[j].x, p[j].y,   x0, y0, x1, y1,   x, y)) {
      hits++;
      ans[side].push_back(p[i]);
      if (cmp(p[i].x, x) != 0 or cmp(p[i].y, y) != 0) {
        ans[side].push_back(PT(x, y));
      }
      side ^= 1;
      ans[side].push_back(PT(x, y));
    } else {
      ans[side].push_back(p[i]);
    }
  }
  if (hits < 2)
    return p;

  if (cmp(ans[0][0].y, y0) != -1) // greater than or equal
    return ans[1];
  return ans[0];
}


// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}

double ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}


void solve(int n) {
  double d, l;
  cin >> d >> l;
  vector<PT> poly(n);
  double maxy = 0;
  for (int i = 0; i < n; ++i) {
    cin >> poly[i].x >> poly[i].y;
    maxy = max(maxy, poly[i].y);
  }

  vector<PT> aaa = cut(poly, 0, 20, 100, 20);

  double L = l * 1000; // cm3
  double lo = 0, hi = maxy;

  while (cmp(lo, hi) == -1) {
    double mid = (lo + hi) * 0.5;
    vector<PT> s = cut(poly, 0, mid, 100, mid);
    double vol = ComputeArea(s) * d;
    if (cmp(vol, L) == 0) {
      lo = mid;
      break;
    }

    if (cmp(vol, L) == 1) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << fixed << setprecision(2) << lo + EPS << endl;
}

int main() {
  int n;
  while (cin >> n) solve(n);
  return 0;
}
