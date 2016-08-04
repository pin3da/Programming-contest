// passed 31/32  tests. Fails on test 29.
// I don't know why ):
#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double T;

struct vec {
  T x, y;
  vec () {}
  vec (T a, T b) : x(a), y(b) {}
  vec operator - (const vec &o) const { return vec(x - o.x, y - o.y);  }
  T cross(const vec &o) const { return x * o.y - y * o.x; }
  T dot(const vec &o) const { return x * o.x + y * o.y; }
};

const long double pi = acos(-1);

long double mtan(vec p) {
  long double ans = atan2l(p.y, p.x);
  if (ans <= 1e-10) ans += 2.0 * pi;
  return ans;
}

struct ev {
  vec p;
  int t;
  long double ang;
  int id;
  ev(vec a, int b, long double c, int d) : p(a), t(b), ang(c), id(d) {}

  bool operator < (const ev &o) const {
    if (ang == o.ang)
      if (t == o.t) return id < o.id;
      else return t < o.t;
    return ang < o.ang;
  }
};

struct line {
  vec start, end;
  int id;
  T dist;

  line(vec a, vec b, int c) : start(a), end(b), id(c) {
    dist = start.dot(start);
  }

  bool operator < (const line &o) const {
    if (dist == o.dist) return id < o.id;
    return dist < o.dist;
  }
};

const int MN = 4 * 100000 + 100;
vec altend[MN];
vec altsta[MN];
set<line>::iterator inv[MN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int s, k, w;
  cin >> s >> k >> w;

  vector<vec> kids(k);
  vector<vec> sw(w), ew(w);
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
    vector<ev> sweep;

    for (int j = 0; j < k; ++j) {
      if (j == i) continue;
      vec p = kids[j] - kids[i];
      sweep.push_back(ev(p, 0, mtan(p), j));
    }

    int ids = k;
    for (int j = 0; j < w; ++j) {
      vec start = sw[j] - kids[i];
      vec end = ew[j] - kids[i];
      if (mtan(start) > mtan(end)) swap(start, end);
      assert(start.cross(end) != 0);
      if (start.cross(end) < 0) {
        sweep.push_back(ev(start, 2, atan2l(start.y, start.x), ids));
        sweep.push_back(ev(end, 1, atan2l(end.y, end.x), ids));
        altend[ids] = start;
        altsta[ids] = end;
        ids++;

        sweep.push_back(ev(start, 2, 2.0 * pi + atan2l(start.y, start.x), ids));
        sweep.push_back(ev(end, 1, 2.0 * pi + atan2l(end.y, end.x), ids));
        altend[ids] = start;
        altsta[ids] = end;
        ids++;
      } else {
        sweep.push_back(ev(start, 1, mtan(start), ids));
        sweep.push_back(ev(end, 2, mtan(end), ids));
        altend[ids] = end;
        altsta[ids] = start;
        ids++;
      }
    }

    sort(sweep.begin(), sweep.end());

    set<line> alive;

    int ans = 0;
    for (int j = 0; j < sweep.size(); ++j) {
      ev &e = sweep[j];
      // cout << e.t << " : " << e.id << " : " << e.p.x << " - " << e.p.y << " a: " << e.ang << endl;
      if (j) {
        assert(e.ang > sweep[j - 1].ang);
      }
      if (e.t == 1) {
        inv[e.id] = alive.insert(line(altsta[e.id], altend[e.id], e.id)).first;
      } else if (e.t == 2) {
        alive.erase(inv[e.id]);
      } else {
        if (alive.size() == 0) {
          ans++;
          continue;
        }
        line tmp = *(alive.begin());
        vec beep = e.p - tmp.start;
        vec boop = tmp.end - tmp.start;
        vec extra = kids[i] - tmp.start;
        assert(beep.cross(boop) != 0);
        if (beep.cross(boop) < 0) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
