#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

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
double dist(PT p, PT q)    { return sqrt(dist2(p, q)); }
int main() {
  int n;
  while (cin >> n) {
    PT t;
    vector<PT> p(4);
    while (n--) {
      cin >> t.x >> t.y;
      if (t.x > p[0].x) p[0] = t;
      if (t.x < p[1].x) p[1] = t;
      if (t.y > p[2].y) p[2] = t;
      if (t.y < p[3].y) p[3] = t;
    }

    double best = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        best = max(best, dist(p[i], p[j]));
      }
    }
    cout << fixed << setprecision(10) <<  best << endl;
  }
  return 0;
}
