const int MAX = 1e9;
// return squared distance
ll closestPair(vector<Point> pt, Point& p, Point& q) {
  if (a.size() < 2) return -1;
  // sort by y
  sort(pt.begin(), pt.end(), [](const Point& a, const Point& b) {
	return (a.y == b.y && a.x < b.x) || a.y < b.y;
  });
  ll sqrDist = (a[1] - a[0]).norm();
  p = a[0], q = a[1];

  set<Point> st;  // ordered set by x
  for (Point a : pt) {
	ll d = sqrt(sqrDist);
	Point cur(a.x - d, -MAX - 1);
	while (1) {
	  auto it = st.upper_bound(cur);
	  if (it == st.end()) break;
	  cur = *it;
	  if (cur.x > a.x + d) break;
	  if (cur.y < a.y - d) {
		st.erase(it);
		continue;
	  }
	  if (minimize(sqrDist, (a - cur).norm())) p = a, q = cur;
	}
	st.insert(a);
  }
  return sqrDist;
}