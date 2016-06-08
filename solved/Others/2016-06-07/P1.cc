#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c, d, e, f;
  while (cin >> a >> b >> c >> d >> e >> f) {
    bool ok = (c + e <= a && max(d, f) <= b) ||
              (c + f <= a && max(d, e) <= b) ||
              (c + e <= b && max(d, f) <= a) ||
              (c + f <= b && max(d, e) <= a) ||
              (max(c, e) <= a && d + f <= b) ||
              (max(c, f) <= a && d + e <= b) ||
              (max(c, e) <= b && d + f <= a) ||
              (max(c, f) <= b && d + e <= a);
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
