#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c;
  while (cin >> a >> b >> c) {
    vector<double> t = {a, b, c};
    sort(t.rbegin(), t.rend());
    a = t[0];b = t[1];c = t[2];
    if (cmp(a, b + c) != -1) {
      cout << "NAO FORMA TRIANGULO" << endl;
      continue;
    }
    if (cmp(a * a, b * b + c * c) == 0) {
      cout << "TRIANGULO RETANGULO" << endl;
    }
    if (cmp(a * a, b * b + c * c) == 1) {
      cout << "TRIANGULO OBTUSANGULO" << endl;
    }
    if (cmp(a * a, b * b + c * c) == -1) {
      cout << "TRIANGULO ACUTANGULO" << endl;
    }
    if (cmp(a, b) == cmp(b, c) && cmp(a, c) == 0) {
      cout << "TRIANGULO EQUILATERO" << endl;
    } else if (cmp(a, b) == 0  || cmp(a, c) == 0 || cmp(b, c) == 0) {
      cout << "TRIANGULO ISOSCELES" << endl;
    }
  }

  return 0;
}
