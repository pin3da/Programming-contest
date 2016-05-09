#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c;
  cout << fixed << setprecision(5);
  while (cin >> a >> b >> c) {
    if (a == 0 || (b * b - 4 * a * c) < 0)
      cout << "Impossivel calcular" << endl;
    else {
      cout << "R1 = " << (-b + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
      cout << "R2 = " << (-b - sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
    }
  }
  return 0;
}
