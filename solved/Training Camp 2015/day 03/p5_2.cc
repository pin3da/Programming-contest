#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cpx;
void solve(double x[], double y[]) { //, double tx[], double ty[]) {
  cpx z1(x[0], y[0]), z2(x[1], y[1]), z3(x[2], y[2]);

  cpx A(3);
  cpx B = cpx(-2, 0) * (z1 + z2 + z3);
  cpx C = z3 * (z1 + z2) + z1*z2;

  cpx f1 = (-B + sqrt(B*B - cpx(4)*A*C)) / (cpx(2)*A);
  cpx f2 = (-B - sqrt(B*B - cpx(4)*A*C)) / (cpx(2)*A);

  cpx tang(x[1] - x[0], y[1] - y[0]);
  tang = z1 + cpx(0.5)*tang;
  
  double ans_dist = abs(f1 - tang) + abs(f2 - tang);

  if (f1.real() > f2.real())
    swap(f1, f2);
  else if (fabs(f1.real() - f2.real()) <= 1E-9 and f1.imag() > f2.imag())
    swap(f1, f2);
  
  printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n", f1.real(), f1.imag(), f2.real(), f2.imag(), ans_dist);
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    double x[3], y[3];
    for (int j = 0; j < 3; j++)
      cin >> x[j] >> y[j];
    
    cout << i+1 << " ";
    solve(x, y);
  }
  return 0;
}
