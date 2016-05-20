#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double eps = 1e-9;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double v;
  long long n, m;
  cout << fixed << setprecision(2);
  while (cin >> v >> n >> m) {
    if (v + n + m == 0)
      break;
    if ((n % 10000) == (m % 10000)) {
      cout << v * 3000 + eps << endl;
    } else if ((n % 1000) == (m % 1000)){
      cout << v * 500 + eps << endl;
    } else {
      n %= 100;
      m %= 100;
      if (m == n) {
        cout << v * 50 + eps << endl;
      } else {
        if (n == 0) n = 100;
        if (m == 0) m = 100;
        n += 3; m += 3;
        if ((n / 4) == (m / 4))
          cout << v * 16 + eps << endl;
        else
          cout << 0.0 + eps << endl;
      }
    }
  }
  return 0;
}
