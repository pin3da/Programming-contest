#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double v, d;
  cout << fixed << setprecision(2);
  while (cin >> v >> d) {
    double r = d * 0.5;
    double h = v / (r * r * 3.14);
    cout << "ALTURA = " << h << endl;
    cout << "AREA = " << (r * r * 3.14) << endl;
  }
  return 0;
}
