using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

const int MN = 30;
const double eps = 1e-9;
double r;
double dia;
int n;

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y)    {}
  point operator + (const point &p)  const { return point(x+p.x, y+p.y); }
  point operator - (const point &p)  const { return point(x-p.x, y-p.y); }
  point operator * (double c)     const { return point(x*c,   y*c  ); }
  point operator / (double c)     const { return point(x/c,   y/c  ); }
};

point p[MN];

int cmp(double x, double y = 0, double tol = eps){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double dot(point p, point q) { return p.x*q.x + p.y*q.y; }
double dist(point p, point q) {return sqrt(dot(p - q, p - q));}
double norm(point p) {return sqrt(dot(p, p));}
point RotateCCW90(point p)   { return point(-p.y,p.x); }
point RotateCW90(point p)    { return point(p.y,-p.x); }

ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << "," << p.y << ")";
}

pair<point, point> compute_center(point a, point b) {
  double d = dist(a, b) * 0.5;
  double h = sqrt(r*r - d*d);
  point vec = a - b;
  vec = (vec / norm(vec)) * h;
  point op1 = RotateCW90(vec)  + (b + ((a - b) * 0.5));
  point op2 = RotateCCW90(vec) + (b + ((a - b) * 0.5));
  return make_pair(op1, op2);
}


int count(point center) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (cmp(dist(center, p[i]), r) != 1)
      ans++;
  }
  return ans;
}

void solve(){
  cin>>r>>n;
  dia = r * 2.0;
  for (int i = 0; i < n; ++i)
    cin>>p[i].x>>p[i].y;

  int ans = 0;
  if (n != 0)
    ans = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (cmp(dist(p[i], p[j]), dia) == -1) {
        pair<point, point> center = compute_center(p[i], p[j]);
        ans = max(ans, count(center.first));
        ans = max(ans, count(center.second));
      } else if (cmp(dist(p[i], p[j]), dia) == 0) {
        point center = p[j] + ((p[i] - p[j]) * 0.5);
        ans = max(ans, count(center));
      }
    }
    ans = max(ans, count(p[i]));
  }

  cout<<ans<<endl;
}


int main() { ___

  int tc;cin>>tc;
  for (int i = 0; i < tc; ++i)
    solve();
  return 0;
}
