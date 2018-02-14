#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

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
  bool operator<(const PT &o) const {
    return make_pair(x, y) < make_pair(o.x, o.y);
  }
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

void solve() {
  int n; cin >> n;
  vector<PT> c(n);
  vector<double> r(n);

  for (int i = 0; i < n; i++) {
    cin >> c[i].x >> c[i].y >> r[i];
  }
  if (n == 1) {
    cout << 2 << endl;
  }

  if (n == 2) {
    int inter = CircleCircleIntersection(c[0], c[1], r[0], r[1]).size();
    if (inter > 1) {
      cout << 4 << endl;
    } else {
      cout << 3 << endl;
    }
  }

  if (n == 3) {

    set<PT> inter;
    set<PT> mine[3];
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        auto tmp = CircleCircleIntersection(c[i], c[j], r[i], r[j]);
        for (auto it: tmp) {
          inter.insert(it);
          mine[i].insert(it);
          mine[j].insert(it);
        }
      }
    }

    int c = 1;

    int edges = 3;
    int v = inter.size();
    for (int i = 0; i < 3; i++) {
      if (mine[i].size() == 0) {
        c++;
        v++;
      } else {
        edges += mine[i].size() - 1;
      }
    }

    cout << edges + c + 1 - v << endl;

  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
    solve();
  return 0;
}

