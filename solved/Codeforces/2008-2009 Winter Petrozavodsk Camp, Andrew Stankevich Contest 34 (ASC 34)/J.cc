#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef long double T;

struct point {
  T x,y; point(){} point(T x, T y) : x(x), y(y){}
  T length() const { return sqrtl(x*x + y*y); }
};

point operator + (const point &a, const point &b) {
  return point(a.x + b.x, a.y + b.y);
}
point operator - (const point &a, const point &b) {
  return point(a.x - b.x, a.y - b.y);
}
point operator / (const point &a, T s) {
  return point(a.x / s, a.y / s);
}
T operator ^ (const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}
T operator * (const point &a, const point &b) {
  return a.x * b.x + a.y * b.y;
}

typedef pair<point, T> circle;

const T EPS = 1e-8;
int cmp(T x, T y = 0, T tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


T dis(point p, point q) {
  T x = p.x - q.x;
  T y = p.y - q.y;
  return sqrt(x * x + y * y);
}
bool in_circle(circle c, point p){
  return cmp(dis(p, c.first), c.second) < 0;
}

point circumcenter(point p, point q, point r) {
  point a = p - r, b = q - r;
  point c = point(a * (p + r) / 2, b * (q + r) / 2);
  T x = c ^ point(a.y, b.y);
  T y = point(a.x, b.x) ^ c;
  T d = a ^ b;
  return point(x, y) / d;
}

point rotate(point p, T t) {
  return point(p.x * cos(t) - p.y * sin(t),
      p.x * sin(t) + p.y * cos(t));
}

point findc(point p, point q, T r, int side) {
  T d = dis(p, q)  * 0.5;
  T alpha = acos(d / r);
  point c = ((q - p) / 2.0) + p;
  return rotate(c, side * alpha);
}

bool check(circle center, vector<point> &a, vector<point> &b) {
  int ok = true;
  for (size_t i = 0; i < b.size() && ok; ++i) {
    if (in_circle(center, b[i])) ok = false;
  }
  for (size_t i = 0; i < a.size() && ok; ++i) {
    if (cmp(dis(center.first, a[i]), center.second + EPS) == 1) ok = false;
  }
  return ok;
}

bool solve2(vector<point> &a, vector<point> &b, circle &ans) {

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = i + 1; j < a.size(); ++j) {
      point p = a[i];
      point q = a[j];
      T lo = dis(p, q) * 0.5;
      T hi = 1e9;
      int iter = 80;
      while (cmp(lo, hi) == -1 && iter--) {
        T mid = (lo + hi) * 0.5;
        circle center;
        center.first = findc(p, q, mid, -1);
        center.second = mid;
        if (check(center, a, b)) {
          lo = mid;
          continue;
        }
        center.first = findc(p, q, mid, 1);
        if (check(center, a, b)) {
          lo = mid;
          continue;
        }
        hi = mid;
      }
      circle center;
      center.first = findc(p, q, lo, 1);
      center.second = lo;
      if (check(center, a, b)) {
        ans = center;
        return true;
      }
    }
  }
  return false;
}


bool solve(vector<point> &a, vector<point> &b, circle &ans) {
  circle center;
  int n = a.size();
  int t = solve2(a, b, ans);
  if (n == 2) return t;
  if (t) {
    return true;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        center.first = circumcenter(a[i], a[j], a[k]);
        center.second = dis(a[i], center.first);
        if (check(center, a, b)) {
          ans = center;
          return true;
        }
      }
    }
  }
  return false;
}

int main() {

#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
  freopen("wall.in", "r", stdin);
  freopen("wall.out", "w", stdout);
#endif

  int n, m;
  cout << fixed << setprecision(12);
  while (cin >> n >> m) {
    vector<point> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i].x >> a[i].y;

    vector<point> b(m);
    for (int i = 0; i < m; ++i)
      cin >> b[i].x >> b[i].y;

    circle center;

    if (solve(a, b, center)) {
      cout << "YES" << endl;
      cout << center.first.x << ' ' << center.first.y << ' '
        << center.second << endl;
    } else {
      if (solve(b, a, center)) {
        cout << "YES" << endl;
        cout << center.first.x << ' ' << center.first.y << ' '
          << center.second << endl;
      } else
        cout << "NO" << endl;
    }
  }

  return 0;
}
