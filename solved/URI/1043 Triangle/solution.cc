#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<double> a(3);
  for (double &i : a)
    cin >> i;

  vector<double> b = a;
  sort(a.begin(), a.end());
  if (a[2] + 0.0000000001 < (a[1] + a[0])) {
    double p = (a[0] + a[1] + a[2]);
    cout << "Perimetro = " << fixed << setprecision(1) << p << endl;
  } else {
    cout << "Area = " << fixed << setprecision(1) << (b[0] + b[1]) * 0.5 * b[2] << endl;
  }

  return 0;
}
