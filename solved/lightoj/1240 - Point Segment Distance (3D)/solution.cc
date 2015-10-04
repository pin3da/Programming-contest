using namespace std;
#include<bits/stdc++.h>

typedef long double Double;

struct Point {
  Double x, y, z;
  Point(){}
  Point(Double x, Double y, Double z) : x(x), y(y), z(z) {}

  Point operator + (const Point &p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }

  Point operator - (const Point &p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }

  Double length() const {
    return sqrtl(*this * *this);
  }

  // Dot product
  Double operator * (const Point &p) const {
    return x*p.x + y*p.y + z*p.z;
  }

  // Cross product
  Point operator ^ (const Point &v) const {
    return Point(y*v.z - v.y*z, -x*v.z + v.x*z, x*v.y - v.x*y);
  }

  void normalize() {
    Double d = length();
    x /= d; y /= d; z /= d;
  }
};

// Scalar times vector product
Point operator * (Double t, const Point &p) {
  return Point(t * p.x, t * p.y, t * p.z);
}

// Returns the shortest distance from point p to the segment
// from a to b.
// This works on 2D and 3D.
Double distance_point_to_segment(const Point &p, const Point &a,
    const Point &b) {
  Point u = b - a;
  Point v = p - a;
  Double t = (u * v) / (u * u);
  if (t < 0.0) t = 0.0;
  if (t > 1.0) t = 1.0;
  // Actual closest point is a + t*(b - a).
  Point boom = a + t*u;
  return (boom - p).length();
}

void solve() {
  Point a, b, p;
  cin >> a.x >> a.y >> a.z;
  cin >> b.x >> b.y >> b.z;
  cin >> p.x >> p.y >> p.z;
  printf("%.10lf\n", (double)(distance_point_to_segment(p, a , b)));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
