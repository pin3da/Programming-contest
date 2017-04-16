#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct point {
  double x, y;
};

inline double distsqr(const point &a, const point &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const point &a, const point &b){
  return sqrt(distsqr(a, b));
}

double distance_point_to_segment(const point &a,const point &b,
    const point &pnt){
  double u =
    ((pnt.x - a.x)*(b.x - a.x) + (pnt.y - a.y)*(b.y - a.y))
    /distsqr(a, b);
  point intersection;
  intersection.x = a.x + u*(b.x - a.x);
  intersection.y = a.y + u*(b.y - a.y);
  if (u < 0.0 || u > 1.0){
    return min(dist(a, pnt), dist(b, pnt));
  }
  return dist(pnt, intersection);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n; cin >> n;
  vector<point> all(n);
  for (auto &i : all)
    cin >> i.x >> i.y;

  double ans = 1e100;
  for (int i = 0; i < n; ++i) {
    int a = (i - 1 + n) % n;
    int b = (i + 1) % n;
    ans = min(ans, distance_point_to_segment(all[a], all[b], all[i]));
  }
  cout << fixed << setprecision(10);
  cout << ans * 0.5 << endl;
  return 0;
}
