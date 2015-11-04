using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define PW(x) ((x)*(x))

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double sebas(double mu, double x, double xe, double ye, double h, double p) {
  double ans = ( (xe - p) * sqrt(PW(h) + PW(p - x))) / ((p - x) * sqrt(PW(xe - p) + PW(ye - h)));
  return ans - mu;
}

bool fun(double mu, double x, double xe, double ye, double h, double W) {
  double a = sebas(mu, x, xe, ye, h, x + 1);
  double b = sebas(mu, x, xe, ye, h, W);
  return cmp(a * b, 0) != 1;
}

void solve() {
  double W, H, x, xe, ye, mu;
  cin >> W >> H >> x >> xe >> ye >> mu;
  double lo = 0, hi = H;
  bool seen = false;
  while (cmp(lo, hi) == -1) {
    double mid = (lo + hi) * 0.5;
    bool f = fun(mu, x, xe, ye, mid, W);
    if (f) {
      hi = mid;
      seen = true;
    } else
      lo = mid;
  }

  if (seen) {
    cout << fixed << setprecision(4) << lo + EPS << endl;
  } else {
    cout << "Impossible" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    solve();
  }
  return 0;
}
