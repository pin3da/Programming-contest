#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
long double dist(long double a, long double b,
                 long double c, long double d) {
  long double x = a - c, y = b - d;
  return sqrt(x * x + y * y);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long double r1, x1, y1, r2, x2, y2;
  while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
    if (dist(x1, y1, x2, y2) + r2 > r1)
      cout << "MORTO" << endl;
    else
      cout << "RICO" << endl;
  }
  return 0;
}
