// http://codeforces.com/contest/596/problem/A

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    if (n <= 1) {
      int x, y; cin >> x >> y;
      cout << -1 << endl;
      continue;
    }

    if (n >= 3) {
      int x, y;
      cin >> x >> y;
      int mx = x, mmx = x, my = y, mmy = y;
      n--;
      while (n--) {
        cin >> x >> y;
        mx = min(mx, x);
        my = min(my, y);
        mmx = max(mmx, x);
        mmy = max(mmy, y);
      }
      cout << (mmx - mx) * (mmy - my) << endl;
      continue;
    }

    assert(n == 2);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = abs(a - c), y = abs(d - b);
    if (x * y == 0)
      cout << -1 << endl;
    else
      cout << x * y << endl;
  }

  return 0;
}
