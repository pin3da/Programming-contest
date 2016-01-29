#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a [] = {-0.000001, 25.0, 50.0, 75.0};
  double b [] = {25, 50, 75, 100};
  double t;
  cin >> t;
  for (int i = 0; i < 4; ++i) {
    if (t > a[i] && t <= b[i]) {
      cout << "Intervalo ";
      cout << (i ? "(" : "[");
      cout << (int)round(a[i]) << ","  << (int)round(b[i]);
      cout << "]" << endl;
      return 0;
    }
  }
  cout << "Fora de intervalo" << endl;
  return 0;
}
