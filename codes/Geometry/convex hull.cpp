vector<Point> convexHull(vector<Point> pt) {
  sort(pt.begin(), pt.end());
  vector<Point> hull(pt.size() + 1);
  int siz = 0;
  for (int i = 0; i < n; i++) {
	while (siz >= 2 && ccw(hull[siz - 2], hull[siz - 1], pt[i]) == -1)
	  --siz;  // check ccw != 1 to exclude collinear
	hull[siz++] = pt[i];
  }
  for (int i = n - 2, last = siz; i >= 0; i--) {
	while (siz - last >= 1 && ccw(hull[siz - 2], hull[siz - 1], pt[i]) == -1)
	  --siz;
	hull[siz++] = pt[i];
  }
  if (siz) {  // sort to ccw order
	hull.resize(siz - 1);
	reverse(hull.begin() + 1, hull.end());
  }
  return hull;
}
