#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c, d;
  cout << fixed << setprecision(4);
  while (cin >> a >> b >> c >> d) {
    double x = a - c,
           y = b - d;
    cout << sqrt(x * x + y * y) << endl;
  }

  return 0;
}
