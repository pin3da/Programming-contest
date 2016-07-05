#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double T;

struct point {
  T x, y;
};

const T EPS = 1e-10;
int cmp(T x, T y = 0, T tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool center(const point &p, const point &q, const point &r, point &c) {
  T ax = q.x - p.x;
  T ay = q.y - p.y;
  T bx = r.x - p.x;
  T by = r.y - p.y;
  T d = ax*by - bx*ay;

  if (cmp(d, 0) == 0) {
    return false;
  }

  T cx = (q.x + p.x) / 2;
  T cy = (q.y + p.y) / 2;
  T dx = (r.x + p.x) / 2;
  T dy = (r.y + p.y) / 2;

  T t1 = bx*dx + by*dy;
  T t2 = ax*cx + ay*cy;

  T x = (by*t2 - ay*t1) / d;
  T y = (ax*t1 - bx*t2) / d;

  c.x = x, c.y = y;
  return true;
}

T ds(const point &a, const point &b) {
  T x = a.x - b.x, y = a.y - b.y;
  return x * x + y * y;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<point> p(n);
    for (auto &i : p) cin >> i.x >> i.y;
    if (n <= 2) {
      cout << n << endl;
      continue;
    }
    int best = 2;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          int ans = 0;
          point c;
          if (center(p[i], p[j], p[k], c)) {
            T r = ds(c, p[i]);
            for (int m = 0; m < n; ++m) {
              if (cmp(r, ds(c, p[m])) == 0)
                ans++;
            }
            best = max(best, ans);
          }
        }
    cout << best << endl;
  }
  return 0;
}
