#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'



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


// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
  vector<PT> ret;
  b = b-a;
  a = a-c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}

const double pi = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double ra, rb;
  cout << fixed << setprecision(3);
  while (cin >> ra >> rb) {
    double r = ra + rb;
    vector<PT> inter = CircleLineIntersection(PT(ra - rb, 100), PT(ra - rb, -100), PT(0, 0), ra + rb);
    double num = dot(inter[1], inter[0]);
    num /= (sqrt(dot(inter[1], inter[1])) * sqrt(dot(inter[0], inter[0])));
    double alpha = acos(num) * 0.5;
    double area = alpha * r * r;
    double tmp = fabs(cross(inter[1], inter[0])) * 0.5;
    area = area - tmp - pi * rb * rb;
    cout << area  + EPS << endl;
  }

  return 0;
}
