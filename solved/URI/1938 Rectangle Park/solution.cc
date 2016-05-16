#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct point {
  long long x, y;
  point() {}
  point(long long a, long long b) : x(a), y(b) {}
  bool operator < (const point &o) const {
    if (x == o.x)
      return y < o.y;
    return x < o.x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<point> p(n);
    for (auto &i : p) cin >> i.x >> i.y;
    sort(p.begin(), p.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      long long yupper = 1LL << 40;
      long long ylower = -(1LL << 40);
      for (int j = i + 1; j < n; ++j) {
        if (p[j].y > p[i].y) {
          if (p[j].y < yupper) {
            ans++;
            yupper = p[j].y;
          }
        } else {
          if (p[j].y > ylower) {
            ans++;
            ylower = p[j].y;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
