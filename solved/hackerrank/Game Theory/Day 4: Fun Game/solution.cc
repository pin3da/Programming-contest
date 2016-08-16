#include <bits/stdc++.h>

using namespace std;

struct st {
  int x, y;
  bool operator < (const st &o) const {
    return (x + y) < (o.x + o.y);
  }
};

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<st> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i].x;
    for (int i = 0; i < n; ++i)
      cin >> a[i].y;

    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (i & 1) ? -a[i].y : a[i].x;
    }
    puts((ans >= 0) ? (ans > 0) ? "First" : "Tie" : "Second");
  }

  return 0;
}
