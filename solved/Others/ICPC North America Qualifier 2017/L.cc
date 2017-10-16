#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long double EPS = 1e-9;
int cmp(long double x, long double y = 0, long double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

long double cos_h(long double x) {
  return (exp(x) + exp(-x)) * 0.5;
}

long double sin_h(long double x) {
  return (exp(x) - exp(-x)) * 0.5;
}

long double comp_s(long double d, long double a) {
  return a * cos_h(d / (2 * a)) - a;
}

long double comp_len(long double d, long double a) {
  return 2 * a * sin_h(d / (2 * a));
}

void solve() {
  long double d, s; cin >> d >> s;
  long double lo = 1e-9, hi = 1e6;
  int max_iter = 1000;

  while (lo < hi && (max_iter--) > 0) {
    long double mid = (lo + hi) * 0.5;
    long double f = comp_s(d, mid);
    if (cmp(f, s) == -1) {
      hi = mid;
    } else if (cmp(f, s) == 1) {
      lo = mid;
    } else {
      lo = mid;
      break;
    }
  }
  cout << fixed << setprecision(8) << comp_len(d, lo) << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  solve();
  return 0;
}
