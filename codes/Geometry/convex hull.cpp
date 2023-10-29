const int N = 5e4 + 1;
int n;
int k = 0;

struct Points {
  long double x, y;
  Points(long double _x, long double _y) {
	x = _x;
	y = _y;
  }

  Points() {}
} points[N], poly[N];

bool ccw(Points a, Points b, Points c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool cw(Points a, Points b, Points c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

long double Get_Area(Points a, Points b, Points c) {
  return (a.x * b.y) - (b.x * a.y) + (b.x * c.y) - (c.x * b.y) + (c.x * a.y) - (c.y * a.x);
}

void convex_hull() {
  k = 0;
  sort(points + 1, points + 1 + n, [](Points& x, Points& y) {
	if (x.x == y.x) {
	  return x.y < y.y;
	}
	return x.x < y.x;
  });

  for (int i = 1; i <= n; i++) {
	while (k >= 2 && cw(poly[k - 1], poly[k], points[i])) {
	  k--;
	}
	poly[++k] = points[i];
  }

  for (int i = n - 1, t = k; i >= 1; i--) {
	while (k - t >= 1 && cw(poly[k - 1], poly[k], points[i])) {
	  k--;
	}
	poly[++k] = points[i];
  }
  long double res = 0;
  for (int i = 1; i <= k; i++) {
	for (int j = i + 1; j <= k; j++) {
	  int l = j + 1;
	  int r = k - 1;
	  while (l <= r) {
		int mid = (l + r) >> 1;
		if (Get_Area(poly[i], poly[j], poly[mid]) > Get_Area(poly[i], poly[j], poly[mid + 1])) {
		  Maximize(res, Get_Area(poly[i], poly[j], poly[mid]));
		  r = mid - 1;
		  continue;
		}
		l = mid + 1;
	  }
	}
  }
  cout << setprecision(1) << fixed << res / 2.0 << '\n';
}
