// http://codeforces.com/contest/659/problem/D

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;
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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<PT> a(n + 1);
    for (auto &i: a) cin >> i.x >> i.y;

    PT x = a[1] - a[0],
       y = a[n - 1] - a[0];

    double sign = cross(x, y);

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      x = a[i + 1] - a[i];
      y = a[i - 1] - a[i];
      if (cross(x, y) * sign < 0)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
