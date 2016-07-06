#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef long double T;

const T g = 9.80665;
const T pi = 3.14159;

int main() {
  T h, p1, p2;
  int n;
  T alpha, s;
  cout << fixed << setprecision(5);
  while (cin >> h >> p1 >> p2) {
    cin >> n;
    while (n--) {
      cin >> alpha >> s;
      alpha = alpha * pi / 180.0;
      T sx = s * cos(alpha);
      T sy = s * sin(alpha);
      T z = g * h / (s * s);
      T t = (s / g) * (sin(alpha) + sqrt(sin(alpha) * sin(alpha) + 2 * z));
      T x = sx * t;
      cout << x << " -> ";
      puts((x >= p1 && x <= p2) ? "DUCK" : "NUCK");
    }
  }

  return 0;
}
