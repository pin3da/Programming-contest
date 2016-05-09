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
  double a;
  cout << fixed << setprecision(2);
  while (cin >> a) {
    double extra = 0;
    int per = 0;
    if (cmp(a, 400) != 1) {
      extra = a * 0.15;
      per = 15;
    } else if (cmp(a, 800) != 1) {
      extra = a * 0.12;
      per = 12;
    } else if (cmp(a, 1200) != 1) {
      extra = a * 0.10;
      per = 10;
    } else if (cmp(a, 2000) != 1) {
      extra = a * 0.07;
      per = 7;
    } else {
      extra = a * 0.04;
      per = 4;
    }

    cout << "Novo salario: " << a + extra << endl;
    cout << "Reajuste ganho: " << extra << endl;
    cout << "Em percentual: " << per << " %" << endl;
  }
  return 0;
}
