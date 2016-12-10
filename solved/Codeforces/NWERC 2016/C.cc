#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

typedef long double ld;
const ld EPS = 1e-15;
int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct shield {
  ld lower, upper, factor;
  shield() {}
  shield(ld a, ld b, ld c) : lower(a), upper(b), factor(c) {}
  bool operator < (const shield &o) const {
    return lower < o.lower;
  }
};

ld f(vector<shield> &s, const ld Y, const ld speed) {
  ld x = 0, y = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    // antes de iniciar el shield
    ld t = s[i].lower - y;
    x += speed * t;
    y = s[i].lower;

    // durante el shield
    t = s[i].upper - y;
    x += speed * s[i].factor * t;
    y = s[i].upper;
  }

  // del ultimo shield al target
  ld t = Y - y;
  x += speed * t;
  return x;
}

int main() {
  ld X, Y;
  cin >> X >> Y;
  int sig = (X < 0);
  X = fabs(X);
  Y = fabs(Y);
  int n; cin >> n;
  vector<shield> s(n);
  for (int i = 0; i < n; ++i) {
    ld a, b, c;
    cin >> a >> b >> c;
    s[i] = shield(a, b, c);
  }
  sort(s.begin(), s.end());
  ld lo = EPS, hi = 1e10;
  while (cmp(lo, hi) == -1) {
    ld mid = (lo + hi) * 0.5;
    ld end = f(s, Y, mid);
    if (cmp(end, X) == -1) {
      lo = mid;
    } else if (cmp(end, X) == 1) {
      hi = mid;
    } else {
      break;
    }
  }
  cout << fixed << setprecision(11);
  if (sig)
    cout << -lo << endl;
  else
    cout << lo << endl;
  return 0;
}
