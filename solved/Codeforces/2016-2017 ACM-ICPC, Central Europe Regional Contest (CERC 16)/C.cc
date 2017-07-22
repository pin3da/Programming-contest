#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const double pi = acos(-1);

double norm(double x, double y) {
  return sqrt(x * x + y * y);
}

double fix(string &line) {
  if (line[0] == 'S') return 0;
  if (line[0] == 'C') return pi * 0.5 - 2.0;
  int i = 0;
  while (line[i] == 'T') i++;
  if (line[i] == 'S') {
    double xi = i, yi = 1, x = 0.5, y = sqrt(3) / 2;
    return norm(x - xi, y - yi) - i;
  } else { // circle
    double xi = i + 0.5, yi = 0.5, x = 0.5, y = sqrt(3) / 2;
    double h = norm(x - xi, y - yi);
    double beta = acos(0.5 / h);
    double alpha = atan2(y - yi, x - xi);
    double theta = (alpha - pi * 0.5 - beta);
    double x2 = xi + 0.5 * cos(alpha - beta);
    double y2 = yi + 0.5 * sin(alpha - beta);
    return norm(x2 - x, y2 - y) + 0.5 * theta - xi;
  }

}

int main() {
  int n;
  string line;
  cin >> n >> line;
  int all_tri = true;
  for (auto i : line) all_tri &= (i == 'T');
  double ans = 0;
  if (all_tri) {
    ans = n + n + 1;
  } else {
    ans = n + n + 2;
    ans += fix(line);
    reverse(line.begin(), line.end());
    ans += fix(line);
  }

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
