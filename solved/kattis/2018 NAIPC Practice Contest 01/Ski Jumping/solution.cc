#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const double g = 9.81;
double j, p, H, L, v0;

double f(double l) {
  return -g * 0.5 * (l / v0) * (l / v0) + H + p;
}

double df(double l) {
  return -g * (l / v0) * (1.0 / v0);
}

double dh(double l) {
   if (cmp(l) == -1)
    return 0;
  if (cmp(l, L * 0.5) == -1)
    return H * (-4.0 * (l / (L * L)));
  if (cmp(l, L) == -1)
    return 4.0 * H * (l / L  - 1.0) * (1.0 / L);
  return 0;
}

double h(double l) {
  if (cmp(l) == -1)
    return H;
  if (cmp(l, L * 0.5) == -1)
    return H * (1.0 - 2.0 * (l / L) * (l / L));
  if (cmp(l, L) == -1)
    return 2 * H  * ((l / L) - 1) * ((l / L) - 1);
  return 0;
}

void solve() {
  cin >> j >> p >> H >> L;

  v0 = sqrt(2.0 * g * j);

  double lo = 0, hi = 1e7;
  int max_iters = 500;
  while (max_iters-- && cmp(lo, hi) == -1) {
    double mid = (lo + hi) * 0.5;
    double a = f(mid), b = h(mid);
    if (cmp(a, b) == -1) {
      hi = mid;
    } else if (cmp(a, b) == 1) {
      lo = mid;
    } else {
      break;
    }
  }

  double delta_y = H + p + j - f(lo);
  double speed = sqrt(2.0 * g * delta_y);


  double slope_h = dh(lo);
  double slope_f = df(lo);
  double alpha = abs<double>(atan(slope_h) - atan(slope_f));

  alpha = alpha * 180.0 / (acos(-1));

  cout << lo << " " << speed << " " << alpha << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  cout << fixed << setprecision(12);

  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
