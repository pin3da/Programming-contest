#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long double eps = 1e-12;
const long double c = sqrt((long double)3.0) / 4.0;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int a;
  while (cin >> a) {
    long double l = a;
    long double area = l * l;
    unsigned long long sides = 3;
    while (l > eps) {
      l /= 3.0;
      area += (l * l) * sides;
      sides *= 4;
    }
    cout << fixed << setprecision(2) << area  * c << endl;
  }

  return 0;
}
