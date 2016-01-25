#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double x = -1, y = -1;
  double t;
  while (cin >> t) {
    if (t < 0 || t > 10) {
      cout << "nota invalida" << endl;
      continue;
    }
    if (x == -1)
      x = t;
    else if (y == -1) {
      y = t;
      cout << "media = " << fixed << setprecision(2) << (x + y) * 0.5 << endl;
      break;
    }
  }

  return 0;
}
