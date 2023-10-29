ll doubleTriangleArea(Point a, Point b, Point c) {
  return abs(cross(b - a, c - b));
}

ll doublePolygonArea(Point* a, int n) {
  ll ans = 0;
  for (int i = 0; i < n; ++i)
	ans += cross(a[i], a[(i + 1) % n]);
  return abs(ans);
}

// points in ccw-order, p[0] has smallest y, O(logn)
bool pointInConvexPolygon(Point* convex, int n, Point pt) {
  int L = 1, R = n - 2;
  int pos = -1;
  while (L <= R) {
	int mid = (L + R) >> 1;
	if (ccw(convex[0], convex[mid], pt) == 1) pos = mid, L = mid + 1;
	else R = mid - 1;
  }
  return pointInTriangle(convex[pos], convex[pos + 1], convex[0], pt);
}