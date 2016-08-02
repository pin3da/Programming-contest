#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 3333;
int ans[MN];


long double INF = 1e100;
long double EPS = 1e-12;

struct PT {
  long double x, y;
  PT() {}
  PT(long double x, long double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (long double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (long double c)     const { return PT(x/c,   y/c  ); }
};

long double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long double dist2(PT p, PT q)   { return dot(p-q,p-q); }
long double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << p.x << " " << p.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  PT a, b, c, x, y, z;
  cout << fixed << setprecision(3);
  while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >>
         x.x >> x.y >> y.x >> y.y >> z.x >> z.y) {
    if (a.x  == 0 && a.y  == 0 &&  b.x == 0 && b.y == 0 && c.x  == 0 &&  c.y == 0 &&
        x.x == 0 &&  x.y == 0 && y.x == 0 && y.y == 0 && z.x == 0 && z.y == 0)  break;
    PT A = x - y, B = z - y;
    PT w = A;
    long double area = fabs(cross(A, B)) * 0.5;
    A = (b - a), B = (c - a);
    long double alpha = area / fabs(cross(A, B));
    PT ans1 = (B * alpha) + a;
    PT ans2 = ans1 + (b - a);
    cout << ans2 << " " << ans1 << endl;
  }
  return 0;
}
