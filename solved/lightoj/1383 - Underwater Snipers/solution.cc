using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << (x) << endl

const double eps = 1e-9;

struct point{
  long long x, y;
  point() {}
  point(long long a, long long b) : x(a), y(b) {}
  bool operator < (const point &p) const {
    if (x == p.x)
      return y < p.y;
    return x < p.x;
  }
};

long long dist2(point &a, point &b) {
  long long x = a.x - b.x, y = a.y - b.y;
  return (x * x + y * y);
}

bool check(vector<point> &p, long long cur, int s, long long d) {
  vector<point> interval(p.size());
  for (int i = 0; i < p.size(); ++i) {
    long long h = p[i].y - cur;
    if (h > d)
      return false;
    long long delta = sqrt(1.0 * d * d - 1.0 * h * h);
    interval[i] = point(p[i].x + delta, p[i].x - delta); // (endtime, starttime)
  }
  sort(interval.begin(), interval.end());
  int parts = 0, i = 0;
  while (i < p.size()) {
    long long cur = interval[i].x;
    while (interval[i].y <= cur && i < p.size())
      i++;

    parts++;
    if (parts > s)
      return false;
  }
  return parts <= s;
}

void solve() {
  long long k, n, s, d;
  cin >> k >> n >> s >> d;
  vector<point> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i].x >> p[i].y;

  sort(p.begin(), p.end());

  if (!check(p, k, s, d)) {
    puts("impossible");
    return;
  }
  long long lo = k - d - 10, hi = k;
  while (lo < hi) {
    if (lo + 1 == hi) {
      if (check(p, lo, s, d))
        hi = lo;
      break;
    }
    long long mid = (lo + hi) >> 1;
    if (check(p, mid, s, d)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  printf("%lld\n", k - hi);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
