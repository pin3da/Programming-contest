#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool f(double w, double h, double r1, double r2) {
  double dx = w - r1 - r2, dy = h - r1 - r2;
  if (dx < 0 || dy < 0) return false;
  return dx * dx + dy * dy >= (r1 + r2) * (r1 + r2) && min(h, w) >= 2 * max(r1, r2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double w, h, r1, r2;
  while (cin >> w >> h >> r1 >> r2 && (w + h + r1 + r2) > 0) {
    puts(f(w, h, r1, r2) ? "S" : "N");
  }
  return 0;
}
