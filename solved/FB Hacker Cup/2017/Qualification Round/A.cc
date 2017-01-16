#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const double pi = acos(-1);
const double rad = 50 * 50;
const double eps = 1e-9;

void solve() {
  int p, x, y;
  cin >> p >> x >> y;
  x -= 50;
  y -= 50;
  double alpha = atan2(y, x);
  if (alpha < 0)
    alpha += 2.0 * pi;
  alpha -= (0.5 * pi);
  if (alpha < 0)
    alpha += 2.0 * pi;

  alpha = 2.0 * pi - alpha;

  double len = x * x + y * y;
  double cur = (alpha * 100.0) / (2.0 * pi);
  if (((cur - eps) <= p) && (len - eps) <= rad) {
    cout << "black" << endl;
  } else {
    cout << "white" << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
