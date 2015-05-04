using namespace std;
#include <bits/stdc++.h>

void solve() {
  double a, b;
  char c;
  cin >> a >> c >> b;
  double r = sqrt(a * a + b * b);
  double alpha = atan(b / a);
  double arc = r * alpha;
  double ratio = 400.0 / (2.0 * a + 2 * arc);
  printf("%.10lf %.10lf\n", a * ratio, b * ratio);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
