// http://codeforces.com/contest/215/problem/B

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cout << fixed << setprecision(10);
  while (cin >> n) {
    vector<double> x(n);
    for (auto &i : x) cin >> i;
    int m; cin >> m;
    vector<double> y(m);
    for (auto &i : y) cin >> i;
    int k; cin >> k;
    vector<double> z(k);
    for (auto &i : z) cin >> i;

    sort(x.begin(), x.end());
    double r1 = x.back();

    double a, b; cin >> a >> b;
    double tar = a / b;
    double ans = 0;
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    double i = y.back(), j = z[0];
    // for (auto &i : y) {
     // for (auto &j : z) {
        double lo = EPS, hi = r1 - EPS;
        while (cmp(lo, hi) == -1) {
          double r2 = (lo + hi) * 0.5;
          double t = (r1 * r1 - r2 * r2) * i;
          t /= r2 * r2 * j;
          if (cmp(t, tar) == 0) {
            lo = r2;
            break;
          }

          if (cmp(t, tar) == -1)
            hi = r2;
          else
            lo = r2;
        }
        ans = max(ans, lo);
    //  }
   // }
    cout << ans << endl;
  }
  return 0;
}
