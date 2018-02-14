#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

struct point {
  long long x, y;
  point() {}
  point(long long a, long long b) : x(a), y(b) {}

  bool operator == (const point &o) const {
    return x == o.x && y == o.y;
  }

  bool operator < (const point &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};

struct segment {
  point a, b;

  segment(point x, point y) {
    if (x.x > y.x || (x.x == y.x && x.y > y.y)) swap(x, y);
    a = x;
    b = y;
  }

  long double eval(long long x) {
    long double dx = a.x - b.x;
    long double dy = a.y - b.y;
    long double xx = x - a.x;
    return dy / dx * xx + a.y;
  }

  long long eval(long long x, long long upper) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double xx = x - a.x;
    if (upper) {
      return ceil((dy * xx) / dx  + a.y) - 1;
    } else {
      return floor(dy * xx / dx + a.y) + 1;
    }
  }

  bool operator < (const segment &o) const {
    if (a.x == o.a.x) {
      //if (b.x == o.b.x) return b.y > o.b.y;
      //return b.x < o.b.x;
      return b.y > o.b.y;
    }
    return a.x < o.a.x;
  }

  bool operator == (const segment &o) const {
    return a == o.a && b == o.b;
  }

  bool is_horizontal() {
    return a.y == b.y;
  }

};

std::ostream& operator<<(std::ostream &stream, segment &seg) {
  stream << "[(" << seg.a.x << "," << seg.a.y << "), (" << seg.b.x << "," << seg.b.y << ")]";
  return stream;
}

set<point> gen_lattice(vector<segment> &seg) {
  set<point> ans;

  for (auto &s : seg) {
    int dx = s.b.x - s.a.x;
    int dy = s.b.y - s.a.y;
    int g = __gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    int x = s.a.x;
    int y = s.a.y;
    ans.insert(point(x, y));
    while (x != s.b.x) {
      x += dx;
      y += dy;
      ans.insert(point(x, y));
    }
  }
  return ans;
}

bool point_in_poly(const vector<point> &p, point q) {
  bool c = 0;
  for (int i = 0; i < int(p.size()); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}


vector<point> print_one(vector<point> &poly) {
  int n = poly.size();

  vector<point> ans;

  long long sx = 0, sy = 0;
  for (auto s : poly) {
    sx += s.x;
    sy += s.y;
  }

  sx /= n;
  sy /= n;

  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      long long px = sx + i,
                py = sy + j;
      if (point_in_poly(poly, point(px, py))) {
        // cout << px << " " << py << endl;
        ans.emplace_back(px, py);
        return ans;
      }
    }
  }

  return ans;
}

void solve() {
  int n; cin >> n;
  vector<point> all(n);
  double start = 0;
  for (auto &it : all) {
    cin >> it.x >> it.y;
    start += double(it.x) / n;
  }


  vector<point> ans;

  if (n < 20) {
    auto tmp = print_one(all);
    if (tmp.size()) ans.push_back(tmp.back());
  }

  vector<segment> seg;
  for (int i = 0; i + 1 < n; i++) {
    seg.emplace_back(all[i], all[i + 1]);
  }
  seg.emplace_back(all[n - 1], all[0]);

  sort(seg.begin(), seg.end());


  long long cur_x = seg[0].a.x + 1;
//  long long cur_x = round(start);
  long long last_x = seg.back().b.x;

  auto upper = seg[0];
  auto lower = seg[1];
  if (lower.b.y > upper.b.y) swap(lower, upper);
  debug(lower, upper);

  size_t target = n / 10;

  int m = seg.size();
  int i = 2;
  while (ans.size() < target && cur_x < last_x) {

    while (i < m && seg[i].a.x <= cur_x) {
      if (i < m) {
        if (seg[i].a == upper.b) {
          upper = seg[i];
        } else {
          lower = seg[i];
        }
      }
      i++;
    }

    if ((lower.a.x == lower.b.x) || (upper.a.x == upper.b.x)) {
      cur_x++;
    }  else {

      if (lower.eval(cur_x) > upper.eval(cur_x))
        swap(lower, upper);

      long long lo = lower.eval(cur_x, false);
      long long hi = upper.eval(cur_x, true);

      debug(cur_x, lo, hi);

      while (ans.size() < target && lo <= hi) {
        ans.emplace_back(cur_x, lo);
        lo++;
      }
      cur_x++;
    }
  }

  if (ans.size() < target) {
    cout << -1 << endl;
  } else {
    for (auto it : ans) {
      cout << it.x << " " << it.y << endl;
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
