#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
const double pi = 3.14159;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c;
  cout << fixed << setprecision(3);
  while (cin >> a >> b >> c) {
    cout << "TRIANGULO: " << a * c * 0.5 << endl;
    cout << "CIRCULO: " << pi * c * c << endl;
    cout << "TRAPEZIO: " << (a + b) * c * 0.5 << endl;
    cout << "QUADRADO: " << b * b << endl;
    cout << "RETANGULO: " << a * b << endl;
  }
  return 0;
}
