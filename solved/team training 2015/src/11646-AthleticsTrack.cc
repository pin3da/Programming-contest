#include <bits/stdc++.h>
using namespace std;

double R, theta;

double f(double l, double w) {
  return l + theta * sqrt(l*l + w*w) - 200;
}

double bisect(double a, double b) {
  double l, w;
  do {
    l = 0.5 * (a + b);
    w = R * l;
    
    if (f(l, w) < 0)
      a = l;
    else
      b = l;
  } while (fabs(f(l, w)) > 1E-9);
  return l;
}

int main() {
  double a, b;
  int c = 0;
  while (scanf("%lf : %lf", &a, &b) != EOF) {
    R = b / a;
    theta = atan(R);

    double l = bisect(0, 1E6);
    double w = R * l;
    printf("Case %d: %.10f %.10f\n",++c, l, w);
  }

  return 0;
}
