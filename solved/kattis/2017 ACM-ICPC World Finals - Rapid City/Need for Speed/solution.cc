#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct entry{
  double d, s;
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  double real_t;
  cin >> n >> real_t;
  vector<entry> all(n);
  for (auto &e : all) cin >> e.d >> e.s;

  double lo = -all[0].s;
  for (auto &e : all) lo = max(lo, -e.s + EPS);

  double hi = 2000100;
  int max_iter = 500;
  while ((max_iter--) && (cmp(lo, hi) == -1)) {
    double mid = (lo + hi) * 0.5;
    double cur_t = 0;
    for (auto e : all) cur_t += e.d / (e.s + mid);
    if (cmp(cur_t, real_t) == -1)
      hi = mid;
    else if (cmp(cur_t, real_t) == 1)
      lo = mid;
    else break;
  }

  cout << fixed << setprecision(10);
  cout << lo << endl;

  return 0;
}
