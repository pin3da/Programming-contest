#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef double ld;

struct point {
  ld x, y;
  point() {}
  point(ld a, ld b) : x(a), y(b) {}
  bool operator < (const point &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};

const ld EPS = 1e-9;

int cmp(ld x, ld y = 0, ld tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
typedef vector <point> polygon;

bool segment_line_intersection(ld x0, ld y0,
    ld x1, ld y1, ld x2, ld y2,
    ld x3, ld y3, ld &x, ld &y){

  ld t0 = (y3-y2)*(x0-x2) - (x3-x2)*(y0-y2);
  ld t1 = (x1-x0)*(y2-y0) - (y1-y0)*(x2-x0);
  ld det =(y1-y0)*(x3-x2) - (y3-y2)*(x1-x0);

  if (fabs(det) < EPS){
    return false;
  }else{
    t0 /= det;
    t1 /= det;
    if (cmp(0, t0) <= 0 and cmp(t0, 1) < 0){
      x = x0 + t0 * (x1-x0);
      y = y0 + t0 * (y1-y0);
      return true;
    }
    return false;
  }
}

vector<polygon> split(const polygon &p, ld x0, ld y0,
    ld x1, ld y1) {
  int hits = 0, side = 0;
  ld x, y;
  vector<polygon> ans(2);

  for (int i = 0; i < (int)p.size(); ++i) {
    int j = (i + 1) % p.size();
    if (segment_line_intersection(p[i].x, p[i].y,
          p[j].x, p[j].y,   x0, y0, x1, y1,   x, y)) {
      hits++;
      ans[side].push_back(p[i]);
      if (cmp(p[i].x, x) != 0 or cmp(p[i].y, y) != 0) {
        ans[side].push_back(point(x, y));
      }
      side ^= 1;
      ans[side].push_back(point(x, y));
    } else {
      ans[side].push_back(p[i]);
    }
  }
  return hits < 2 ? vector<polygon>(1, p) : ans;
}

double turn(const point &a, const point &b, const point &c){
  double z = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
  if (fabs(z) < 1e-9) return 0.0;
  return z;
}

void print_point(point &a) {
  cout << a.x << " " << a.y << endl;
}

void print_poly(polygon &p) {
  cout << "poly" << endl;
  for (int i = 0; i < (int)p.size(); ++i) {
    cout << "\t";
    print_point(p[i]);
  }
  cout << "end poly" << endl;
}


bool point_in_poly(point &a, polygon &p) {
  int mask = 0;
  int n = p.size();
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    double z = turn(p[i], p[j], a);
    if (z < 0.0){
      mask |= 1;
    }else if (z > 0.0){
      mask |= 2;
    }else if (z == 0.0) return false;
    if (mask == 3) return false;
  }
  return mask != 0;
}

vector<point> find_line(point &a, point &b) {
  point mid((a.x + b.x) * 0.5 - a.x, (a.y + b.y) * 0.5 - a.y);
  point other(-mid.y, mid.x);
  vector<point> ans;
  ans.emplace_back(mid.x + a.x, mid.y + a.y);
  ans.emplace_back(other.x + a.x + mid.x, other.y + a.y + mid.y);
  return ans;
}

double polygon_area(const vector<point> &p){
  double r = 0.0;
  for (int i = 0; i < (int)p.size(); ++i) {
    int j = (i+1) % p.size();
    r += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(r/2.0);
}

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  polygon box(4);
  box[0] = point(a, b);
  box[1] = point(c, b);
  box[2] = point(c, d);
  box[3] = point(a, d);
  int n; cin >> n;
  vector<point> all(n * 2);
  map<point, int> inv;

  for (int i = 0; i < 2 * n; ++i) {
    cin >> all[i].x >> all[i].y;
    inv[all[i]] = i;
  }

  sort(all.begin(), all.end());

  vector<pair<polygon, point>> state;
  do {
    state.clear();
    point start = all[0];
    state.emplace_back(box, start);

    for (int i = 1; i < 2 * n; ++i) {
      point cur = all[i];
      vector<pair<polygon, point>> next;
      for (auto &poly: state) {
        if (!point_in_poly(cur, poly.first))
          next.push_back(poly);
      }
      for (auto &poly: state) {
        if (point_in_poly(cur, poly.first)) {
          vector<point> inter = find_line(cur, poly.second);
          vector<polygon> cut = split(poly.first, inter[0].x, inter[0].y, inter[1].x, inter[1].y);
          if (point_in_poly(cur, cut[0])) {
            next.emplace_back(cut[0], cur);
            next.emplace_back(cut[1], poly.second);
          } else {
            next.emplace_back(cut[1], cur);
            next.emplace_back(cut[0], poly.second);
          }
          break;
        }
      }

      state = next;
    }

    if (state.size() == n * 2)
      break;
    random_shuffle(all.begin(), all.end());
  } while (true);

  int ans[2] = {0, 0};
  for (auto it : state) {
    double area = polygon_area(it.first);
    ans[inv[it.second] < n] += area;
  }
  cout << (ans[1] > ans[0] ? "Gryffindor" : "Slytherin") << endl;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
