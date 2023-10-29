const ld EPS = 1E-9;

struct Line {
  ld a, b, c;
  Line() {}
  Line(Point s, Point t) {
	a = s.y - t.y;
	b = t.x - s.x;
	c = -a * s.x - b * s.y;
	norm();
  }
  void norm() {
	ld z = sqrt(a * a + b * b);
	if (abs(z) > EPS) a /= z, b /= z, c /= z;
  }
  // can be negative
  ld dist(Point p) const { return a * p.x + b * p.y + c; }
};

inline bool intersect_1d(ld a, ld b, ld c, ld d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d) + EPS;
}

ld det(ld a, ld b, ld c, ld d) {
  return a * d - b * c;
}

bool intersect(Line m, Line n, Point& res) {
  double zn = det(m.a, m.b, n.a, n.b);
  if (abs(zn) < EPS) return false;
  res.x = -det(m.c, m.b, n.c, n.b) / zn;
  res.y = -det(m.a, m.c, n.a, n.c) / zn;
  return true;
}

bool parallel(Line m, Line n) {
  return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(Line m, Line n) {
  return abs(det(m.a, m.b, n.a, n.b)) < EPS &&
         abs(det(m.a, m.c, n.a, n.c)) < EPS &&
         abs(det(m.b, m.c, n.b, n.c)) < EPS;
}

bool segmentIntersect(const Point& a, const Point& b, const Point& c,
                      const Point& d) {
  if (ccw(c, a, d) == 0 && ccw(c, b, d) == 0)
	return intersect_1d(a.x, b.x, c.x, d.x) && intersect_1d(a.y, b.y, c.y, d.y);
  return ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b);
}

inline bool between(ld l, ld r, ld x) {
  return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}
/*
- Intersection of segments a-b and c-d
- left, right: return intersection endpoints
- If intersect at a single point, left == right
*/
bool segmentIntersection(Point a, Point b, Point c, Point d, Point& left,
                         Point& right) {
  if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
	return false;
  Line m(a, b);
  Line n(c, d);
  double zn = det(m.a, m.b, n.a, n.b);
  if (abs(zn) < EPS) {
	if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS) return false;
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);
	left = max(a, c);
	right = min(b, d);
	return true;
  } else {
	left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
	left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
	return between(a.x, b.x, left.x) && between(a.y, b.y, left.y) &&
	       between(c.x, d.x, left.x) && between(c.y, d.y, left.y);
  }
}
