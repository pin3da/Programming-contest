typedef long double ld;

struct Point {
  ll x, y;
  Point(ll x = 0, ll y = 0) : x(x), y(y) {}
  Point operator+(const Point& other) const {
	return Point(other.x + x, other.y + y);
  }
  Point operator-(const Point& other) const {
	return Point(other.x - x, other.y - y);
  }
  bool operator==(const Point& other) const {
	return x == other.x && y == other.y;
  }
  bool operator<(const Point& other) const {
	return x < other.x - EPS ||
	       (std::abs(x - other.x) < EPS && y < other.y - EPS);
  }
  // for vectors
  ll norm() const { return x * x + y * y; }  // x^2 + y^2
  ld abs() const { return sqrt(norm()); }
};

// vector functions
ll dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y;
}
ll cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}
ld proj(Point a, Point b) {  // projection of a onto b
  return dot(a, b) / b.abs();
}
ld angle(Point a, Point b) {
  return acos(dot(a, b) / a.abs() / b.abs());
}
// 0: colinear, -1: turn right, 1: turn left
int ccw(Point a, Point b, Point c) {
  ll res = cross(b - a, c - a);
  if (res == 0) return 0;
  return res < 0 ? -1 : 1;
}