// After ~50 attemps using sweep line (circular) and getting
// wa on test 29, I decided to brute-force the problem. It works, sadly.
// I hate you test 29 ¬¬
#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct point {
  long long x, y;
  point() {}
  point(long long x, long long y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y)    {}
  point operator + (const point &p)  const { return point(x+p.x, y+p.y); }
  point operator - (const point &p)  const { return point(x-p.x, y-p.y); }
};

long long cross(point p, point q)   { return p.x*q.y-p.y*q.x; }

int sig(long long x) {
  return x <= 0 ? (x < 0) ? -1 : 0 : 1;
}
// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(point a, point b, point c, point d) {
  if (sig(cross(d-a, b-a)) * sig(cross(c-a, b-a)) > 0) return false;
  if (sig(cross(a-c, d-c)) * sig(cross(b-c, d-c)) > 0) return false;
  return true;
}

const int MN = 4 * 100000 + 100;
point kids[MN];
point sw[MN];
point ew[MN];

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int s, k, w;
  cin >> s >> k >> w;

  for (int i = 0; i < k; ++i) {
    cin >> kids[i].x >> kids[i].y;
  }
  for (int i = 0; i < w; ++i) {
    cin >> sw[i].x >> sw[i].y;
    cin >> ew[i].x >> ew[i].y;
  }

  if (k == 1) {
    cout << 0 << endl;
    exit(0);
  }

  for (int i = 0; i < s; ++i) {
    int ans = 0;
    for (int j = 0; j < k; ++j) {
      if (j == i) continue;
      int ok = true;
      for (int r = 0; r < w && ok; ++r) {
        if (SegmentsIntersect(kids[i], kids[j], sw[r], ew[r]))
          ok = false;
      }
      if (ok) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
