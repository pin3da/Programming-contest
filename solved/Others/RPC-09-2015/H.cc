#include<bits/stdc++.h>
using namespace std;

const int inf = 2 * 100000001;
struct point{
  int x, y;
  point() {}
  bool operator < (const point &o) const {
    return x < o.x;
  }
};

int main() {
  int n;
  while (cin >> n) {
    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = i + 1;
      int mmin = inf, mmax = -inf;
      while (j < n) {
        if (p[i].y > p[j].y) {
          if (p[j].y > mmax) {
            ans++;
            mmax = p[j].y;
          }
        } else {
          if (p[j].y < mmin) {
            ans++;
            mmin = p[j].y;
          }
        }
        ++j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
