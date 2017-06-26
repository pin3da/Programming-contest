#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct circle {
  int x, y, r;
  circle(int a, int b, int c) : x(a), y(b), r(c) {}
};

bool inter(circle a, circle b) {
  long long x = a.x - b.x, y = a.y - b.y;
  long long r = a.r + b.r;
  return ((x * x + y * y) < r * r);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<circle> all;
  while (n--) {
    char t; cin >> t;
    int x, y, r;
    cin >> x >> y >> r;
    if (t == 'A') {
      int ok = true;
      circle cur(x, y, r);
      for (int i = 0; i < (int) all.size(); ++i) {
        if (inter(cur, all[i])) ok = false;
      }
      if (ok) all.emplace_back(x, y, r);
      puts(ok ? "Ok" : "No");
    } else {
      int ok = false;
      for (int i = 0; i < (int) all.size(); ++i) {
        if (all[i].x == x && all[i].y == y && all[i].r == r) {
          all.erase(all.begin() + i);
          ok = true;
          break;
        }
      }
      puts(ok ? "Ok" : "No");
    }
  }

  return 0;
}
