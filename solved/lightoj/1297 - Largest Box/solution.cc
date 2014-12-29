using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

typedef long double ld;

int cmp(ld x, ld y, ld tol = 1e-9) {
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ld f(ld x, ld w, ld l) {
  return (l - 2.0 * x) * (w - 2 * x) * x;
}

ld solve() {
  ld w, l;
  cin >> l >> w;
  ld lo = 0, hi = min(w, l) * 0.5;
  while (cmp(lo, hi) == -1) {
    ld m1 = (2.0 * lo + hi) / 3.0;
    ld m2 = (2.0 * hi + lo) / 3.0;
    if (cmp(f(m1, w, l), f(m2, w, l)) == -1)
      lo = m1;
    else
      hi = m2;
  }
  return f(lo, w, l);
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cout << "Case " << (i + 1) << ": " << setprecision(15) << solve() << endl;

  return 0;
}
