#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
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
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
double dist(PT p, PT q)    { return sqrt(dist2(p, q));}
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}

double find_best(vector<double> &d, vector<PT> &p, PT a, PT b, PT r, double total) {
  int id_a = -1;
  double best = 1e100;
  for (int i = 0; i < p.size(); ++i) {
    double cur = total - d[i] + dist(p[i], a);
    if (cur < best) {
      best = cur;
      id_a = i;
    }
  }
  double ans = 1e100;
  for (int i = 0; i < p.size(); ++i) {
    if (i == id_a) continue;
    double cur = best - d[i] + dist(p[i], b);
    ans = min(ans, cur);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  PT a, b, r;
  cout << fixed << setprecision(10);
  while (cin >> a.x >> a.y >> b.x >> b.y >> r.x >> r.y) {
    int n; cin >> n;
    vector<PT> p(n);
    vector<double> d(n);
    double total = 0;
    int j = 0;
    for (auto &i : p) {
      cin >> i.x >> i.y;
      d[j] = dist(i, r);
      total += 2.0 * d[j];
      j++;
    }

    double best = total + total;
    best = min(best, find_best(d, p, a, b, r, total));
    best = min(best, find_best(d, p, b, a, r, total));
    for (int i = 0; i < n; ++i) {
      best = min(best, total - d[i] + dist(a, r));
      best = min(best, total - d[i] + dist(b, r));
    }
    cout << best << endl;
  }
  return 0;
}
