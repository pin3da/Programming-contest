#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double ld;
const ld eps = 1e-7;

int cmp(ld x, ld y, ld tol = 1e-15) {
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ld f(ld x, ld w, ld l) {
  return (l - 2.0 * x) * (w - 2 * x) * x;
}

ld solve(ld w, ld l) {
  ld lo = 0, hi = min(w, l) * 0.5;
  while (cmp(lo, hi) == -1) {
    ld m1 = (2.0 * lo + hi) / 3.0;
    ld m2 = (2.0 * hi + lo) / 3.0;
    if (cmp(f(m1, w, l), f(m2, w, l)) == -1)
      lo = m1;
    else
      hi = m2;
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ld w, l;
  cout << fixed << setprecision(3);
  while (cin >> w >> l) {
    cout << solve(w, l) + eps << " " << 0.0 << " " << min(w, l) * 0.5 + eps << endl;
  }

  return 0;
}

