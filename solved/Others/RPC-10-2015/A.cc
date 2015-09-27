#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-9;

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

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  PT v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - RotateCCW90(v)*y);
  return ret;
}

int cmp(double x,double y, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
  int n;
  cin >> n;

  vector<PT> p(n);
  vector<double> r(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y >> r[i];

  vector<PT> inter;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<PT> interij = CircleCircleIntersection(p[i], p[j], r[i], r[j]);
      if (interij.size() == 0) {
	if (cmp((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y), r[j]*r[j]) != 1)
	  interij.push_back(p[i]);
	else if (cmp((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y), r[i]*r[i]) != 1)
	  interij.push_back(p[j]);
      }
      for (int k = 0; k < interij.size(); k++)
	inter.push_back(interij[k]);
    }
  }
  
  int ans = 1;
  for (int i = 0; i < inter.size(); i++) {
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (cmp((inter[i].x - p[j].x)*(inter[i].x - p[j].x) + (inter[i].y - p[j].y)*(inter[i].y - p[j].y), r[j]*r[j]) != 1)
	c++;
    }
    ans = max(ans, c);
  }

  cout << ans << endl;

  return 0;
}
