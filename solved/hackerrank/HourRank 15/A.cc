#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int q; cin >> q;
  while (q--) {
    int x, y, z; cin >> x >> y >> z;
    int d1 = abs(z - x), d2 = abs(z - y);
    if (d1 < d2) {
      cout << "Cat A" << endl;
    } else if (d2 < d1) {
      cout << "Cat B" << endl;
    } else
      cout << "Mouse C" << endl;
  }
  return 0;
}
