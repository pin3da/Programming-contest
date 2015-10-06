#include <bits/stdc++.h>
using namespace std;

double x, y, c;
double f(double h) {
  double term = h * c / (h - c);
  return x*x - y*y - h*h + term*term;
}

double solve() {
  double lo = c, hi = 1E9;
  do {
    double mid = 0.5 * (hi + lo);
    // cout << mid << endl;
    if (f(mid) <= 0)
      hi = mid;
    else
      lo = mid;
  } while (fabs(hi - lo) > 1E-9);

  return sqrt(x*x - hi*hi);
}

int main() {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> x >> y >> c;
    cout << "Case " << i + 1 << ": " << fixed << setprecision(10) << solve() << endl;
  }
  
  return 0;
}
