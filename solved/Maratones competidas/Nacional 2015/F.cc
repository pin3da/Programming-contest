using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define sq(x) ((x)*(x))

int main() {
  #ifdef TCBAHIA
  freopen("f.in", "r", stdin);
  #endif // TCBAHIA

  int n;
  while (cin >> n) {
    vector<double> x(n), y(n), w(n);
    double ax = 0, ay = 0, aw = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> w[i];
      ax += x[i] * w[i];
      ay += y[i] * w[i];
      aw += w[i];
    }
    double cost = 0;
    ax /= aw;
    ay /= aw;
    for (int i = 0; i < n; ++i) {
      cost += w[i] * (sq(x[i] - ax) + sq(y[i] - ay));
    }
    printf("%.3lf\n", cost);
  }
  return 0;
}
