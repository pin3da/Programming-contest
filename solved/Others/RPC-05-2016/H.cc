#include <bits/stdc++.h>

using namespace std;


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
  os << "(" << p.x << "," << p.y << ")";
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  long double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}


// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int a, b; cin >> a >> b;
    vector<PT> polygon(a);
    for (auto &i : polygon)
      cin >> i.x >> i.y;
    PT person;
    int ans = 0;
    while (b--) {
      cin >> person.x >> person.y;
      if (PointInPolygon(polygon, person) && !(PointOnPolygon(polygon, person))) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
