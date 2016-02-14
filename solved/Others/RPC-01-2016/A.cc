#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl
typedef long long ll;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    ll d, x, y;
    cin >> d >> x >> y;
    if (x == 0 and y == 0) {
      cout << 0 << endl;
      continue;
    }

    long double ans = sqrt(x * x + y * y) / sqrt(d);
    if (fabs(ans - floor(ans)) < 1e-9)
      cout << max(1LL, (ll)floor(ans)) << endl;
    else
      cout << max(1LL, (ll)floor(ans)) + 1 << endl;
  }
  return 0;
}
