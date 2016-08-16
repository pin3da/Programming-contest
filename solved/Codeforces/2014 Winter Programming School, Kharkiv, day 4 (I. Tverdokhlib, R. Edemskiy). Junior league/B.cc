#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc; cin >> tc;
  while (tc--) {
    long long n, m;
    cin >> n >> m;
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long dx = llabs(x1 - x2), dy = llabs(y1 - y2);
    long long ox = n - max(x1, x2) + min(x1, x2) - 1,
              oy = m - max(y1, y2) + min(y1, y2) - 1;
    if (dx == 0) {
      if (oy < dy) cout << (dy - oy - 1) * n << endl;
      else cout << 0 << endl;
    } else if (dy == 0) {
      if (ox < dx) cout << (dx - ox - 1) * m << endl;
      else cout << 0 << endl;
    } else {
      long long tmp = 0;
      /*debug(dx);
      debug(ox);
      debug(dy);
      debug(oy);*/
      if ((ox + 1 < dx) && (oy + 1 < dy)) {
        int diff = dx - ox - 1;
        tmp += (dx - ox - 1) * m;
        tmp += (dy - oy - 1) * n;
        tmp -= (diff) * (dy - oy - 1);
        dx = ox + 1;
        dy = oy + 1;
        //debug(dx);
        //debug(dy);
      } else if (ox + 1 < dx) {
        tmp += (dx - ox - 1) * m;
        dx = ox + 1;
      } else if (oy + 1 < dy) {
        tmp += (dy - oy - 1) * n;
        dy = oy + 1;
      }
      /*
      debug(tmp);
      debug(dx);
      debug(dy);*/
      tmp += 2LL * dy * dx;
      cout << tmp << endl;
    }
  }
  return 0;
}
