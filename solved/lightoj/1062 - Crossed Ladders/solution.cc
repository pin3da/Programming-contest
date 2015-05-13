using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

// Stanford lib
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

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}
// Endlib

const double eps = 1e-11;

int cmp(double x, double y) {
  return (x <= y + eps) ? (x + eps < y) ? -1 : 0 : 1;
}

void solve() {
  double x, y, c;
  cin >> x >> y >> c;
  double lo = eps, hi = min(x, y) + eps;
  while (cmp(lo, hi) == -1) {
    double mid = (lo + hi) * 0.5;
    double a1 = sqrt(x * x - mid * mid);
    double a2 = sqrt(y * y - mid * mid);
    PT h = ComputeLineIntersection(PT(0, 0), PT(mid, a1), PT(0, a2), PT(mid, 0));
    if (cmp(h.y, c) == 0)
      break;
    if (cmp(h.y, c) == 1)
      lo = mid;
    else
      hi = mid;

  }
  printf("%.10lf\n", lo + eps);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
