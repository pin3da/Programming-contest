#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
typedef long double dt;
const dt pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  dt l;
  cout << fixed << setprecision(10);
  while (cin >> l) {
    cout << (sin(108 * pi / 180.0) / sin(63 * pi / 180.0)) * l << endl;
  }
  return 0;
}
