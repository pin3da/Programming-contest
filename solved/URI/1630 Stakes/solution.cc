#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x, y;
  while (cin >> x >> y) {
    long long g = __gcd(x, y);
    long long ans = 2 * ((x / g - 1) + (y / g - 1));
    cout << ans + 4 << endl;
  }
  return 0;
}
