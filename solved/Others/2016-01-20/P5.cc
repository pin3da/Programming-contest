#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d && (a + b + c + d)) {
    int dx = fabs(a - c),
        dy = fabs(b - d);

    if (dx == 0 && dy == 0) {
      cout << 0 << endl;
      continue;
    }

    if (dx == 0 || dy == 0 || (dx == dy)) {
      cout << 1 << endl;
      continue;
    }
    cout << 2 << endl;
  }
  return 0;
}
