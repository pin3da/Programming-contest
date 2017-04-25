// http://codeforces.com/contest/459/problem/A

using namespace std;
#include <bits/stdc++.h>

int main() {
  int x1, x2, y1, y2;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }

    int dx = x2 - x1,
        dy = y2 - y1;

    if (dx != 0 && dy != 0 && abs(dx) != abs(dy)) {
      cout << -1 << endl;
      continue;
    }

    if (abs(dx) == abs(dy))
      cout << x2 << " " << y1 << " " << x1 << " " << y2 << endl;
    else if (dx == 0)
      cout << x1 + dy << " " << y1 << " " << x1 + dy << " " << y2 << endl;
    else
      cout << x1 << " " << y1 + dx << " " << x2 << " " << y2 + dx << endl;

  }
  return 0;
}
