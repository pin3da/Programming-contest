#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void solve() {
  int n, k; cin >> n >> k;
  double u; cin >> u;
  vector<double> a(n);
  for (auto &i : a) cin >> i;
  double lo = 0, hi = 1;
  int max_iter = 1000;
  while ((max_iter--) && cmp(lo, hi) == -1) {
    double mid = (lo + hi) * 0.5;
    double need = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < mid) need += mid - a[i];
    }
    if (cmp(need, u) == -1) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  double ans = 1;
  for (int i = 0; i < n; ++i) {
    ans *= max(lo, a[i]);
  }
  printf("%.9lf\n", ans + 1e-9);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
