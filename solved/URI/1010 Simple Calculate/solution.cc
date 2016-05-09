#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c, d, e;
  while (cin >> a >> b >> c >> a >> d >> e)
    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << b * c + d * e << endl;
  return 0;
}
