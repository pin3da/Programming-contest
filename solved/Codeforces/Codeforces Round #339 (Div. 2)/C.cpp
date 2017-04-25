// http://codeforces.com/contest/614/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

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
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}


// compute distance from c to segment between a and b
long double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

void solve(int n) {
  PT p;
  cin >> p.x >> p.y;

  vector<PT> a(n);
  long double mmin = INF, mmax = EPS;
  for (auto &i : a) {
    cin >> i.x >> i.y;
    mmax = max(dist2(p, i), mmax);
  }

  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;

    mmin = min(mmin, DistancePointSegment(a[i], a[j], p));
  }

  long double outer = acos(-1) * mmax;
  long double inner = acos(-1) * mmin * mmin;
  cout << fixed << setprecision(10) << (outer - inner + EPS) << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n) solve(n);
  return 0;
}
