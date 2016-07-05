#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
typedef int T;

struct point {
  T x, y;
  point() {}
  point(T a, T b) : x(a), y(b) {}
  point operator - (const point &o) const {
    return point(x - o.x, y - o.y);
  }
};

T cross(const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}

// checks if the pont q is inside the triangle a-b-c
bool inside(const point &a, const point &b,
    const point &c, const point &q) {

  int mask = 0;
  point l = b - a, r = q - a;
  T z = cross(l, r);
  if (z == 0) return false;
  if (z > 0) mask |= 1;
  if (z < 0) mask |= 2;

  l = c - b, r = q - b;
  z = cross(l, r);
  if (z == 0) return false;
  if (z > 0) mask |= 1;
  if (z < 0) mask |= 2;

  l = a - c, r = q - c;
  z = cross(l, r);
  if (z == 0) return false;
  if (z > 0) mask |= 1;
  if (z < 0) mask |= 2;

  if (mask == 3) return false;
  return mask != 0;
}

point all[111], black[111];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      cin >> black[i].x >> black[i].y;
    for (int i = 0; i < m; ++i)
      cin >> all[i].x >> all[i].y;

    long long total = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          int ans = 0;
          T min_x = min(black[i].x, min(black[j].x, black[k].x));
          T max_x = max(black[i].x, max(black[j].x, black[k].x));
          T min_y = min(black[i].y, min(black[j].y, black[k].y));
          T max_y = max(black[i].y, max(black[j].y, black[k].y));
          for (int q = 0; q < m; ++q) {
            if (all[q].x < min_x || max_x < all[q].x) continue;
            if (all[q].y < min_y || max_y < all[q].y) continue;
            ans += inside(black[i], black[j], black[k], all[q]);
          }
          total += ans * ans;
        }
      }
    }
    cout << total << endl;
  }
  return 0;
}
