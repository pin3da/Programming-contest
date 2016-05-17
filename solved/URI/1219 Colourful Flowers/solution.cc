#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double pi = 3.1415926535897;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c;
  cout << fixed << setprecision(4);
  while (cin >> a >> b >> c) {
    double p = (a + b + c) * 0.5;
    double A = sqrt(p * (p - a) * (p - b) * (p - c));
    double rB = sqrt((p - a) * (p - b) * (p - c) / p);
    double B = pi * rB * rB;
    double rC = (a * b * c) / sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c));
    double C = pi * rC * rC;
    cout << C - A << ' ' << A - B << ' ' << B << endl;
  }
  return 0;
}
