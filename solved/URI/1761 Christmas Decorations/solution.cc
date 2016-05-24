#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double pi = 3.141592654;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c;
  cout << fixed << setprecision(2);
  while (cin >> a >> b >> c) {
    double x = tan(a * pi / 180.0) * b + c;
    cout << x * 5.0 << endl;
  }

  return 0;
}
