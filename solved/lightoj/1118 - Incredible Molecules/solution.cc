using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

double INF = 1e100;
double EPS = 1e-12;
const double pi = acos(-1);

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

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// computes the circular segment of a circle with radious r
// and central angle aplha
double sector(double r, double alpha) {
  return r * r * 0.5 * (alpha - sin(alpha));
}

void solve() {
  int x, y, r, x1, y1, r1;
  cin >> x >> y >> r >> x1 >> y1 >> r1;

  double d = sqrt(dist2(PT(x, y), PT(x1, y1)));
  if (d >= r + r1) {
    puts("0");
    return;
  }
  if (d + r <= r1) {
    printf("%.10lf\n", pi * r * r);
    return;
  }
  if (d + r1 <= r) {
    printf("%.10lf\n", pi * r1 * r1);
    return;
  }

  // using law of cosines
  double ans = sector(r, 2 * acos((r * r + d * d - r1 * r1) / (2.0 * r * d)));
  ans += sector(r1, 2 * acos((r1 * r1 + d * d - r * r) / (2.0 * r1 * d)));
  printf("%.10lf\n", ans);
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
