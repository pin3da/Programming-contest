#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1000123;

struct bit {
  int n;
  int t[MN + 100];

  void add(int where, long long what){
    for (where++; where <= n; where += where & -where){
      t[where] += what;
    }
  }

  void add(int from, int to, long long what) {
    add(from, what);
    add(to + 1, -what);
  }

  long long query(int where){
    long long sum = t[0];
    for (where++; where > 0; where -= where & -where){
      sum += t[where];
    }
    return sum;
  }
};


struct point {
  long long x, y;
};

struct rect {
  point a, b;
};

struct event {
  // t: 0: open rect
  //    1: query point
  //    2: close rect
  int x, t, y1, y2;
  event(int a, int b, int c, int d) : x(a), t(b), y1(c), y2(d) {}
  bool operator < (const event &o) const {
    if (x == o.x) {
      if (t == o.t) {
        if (y1 == o.y1) return y2 < o.y2;
        return y1 < o.y1;
      }
      return t < o.t;
    }
    return x < o.x;
  }
};

void print_ev(event &e) {
  printf("x:%d type:%d y1:%d y2:%d\n", e.x, e.t, e.y1, e.y2);
}

void print_p(point &p) {
  printf("x:%lld y:%lld\n", p.x, p.y);
}

bit tree;

void solve(vector<point> &a, vector<rect> &b) {
  int n = a.size();
  int m = b.size();

  vector<event> all;

  tree.n = MN;

  for (int i = 0; i < n; i++)
    all.emplace_back(a[i].x, 1, a[i].y, i);

  for (int i = 0; i < m; i++) {
    point f = b[i].a;
    point s = b[i].b;
    all.emplace_back(f.x, 2, f.y, s.y);
    all.emplace_back(s.x, 0, f.y, s.y);
  }

  sort(all.begin(), all.end());
  vector<int> ans(n);
  for (auto ev: all) {
    // print_ev(ev);
    if (ev.t == 2) {
      tree.add(ev.y1 + 1, ev.y2 - 1, +1);
    }
    if (ev.t == 0) {
      tree.add(ev.y1 + 1, ev.y2 - 1, -1);
    }
    if (ev.t == 1) {
      ans[ev.y2] += tree.query(ev.y1);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  vector<point> a(n);
  vector<rect> b(m);
  map<long long, int> coord;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    coord[a[i].x] = 1;coord[a[i].y] = 1;
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i].a.x >> b[i].a.y;
    cin >> b[i].b.x >> b[i].b.y;
    coord[b[i].a.x] = 1; coord[b[i].a.y] = 1; coord[b[i].b.x] = 1; coord[b[i].b.y] = 1;
  }

  int id = 0;
  for (auto it: coord) {
    coord[it.first] = id++;
  }

  for (int i = 0; i < n; i++) {
    a[i].x = coord[a[i].x];
    a[i].y = coord[a[i].y];
  }
  for (int i = 0; i < m; i++) {
    b[i].a.x = coord[b[i].a.x];
    b[i].a.y = coord[b[i].a.y];
    b[i].b.x = coord[b[i].b.x];
    b[i].b.y = coord[b[i].b.y];
  }
  solve(a, b);
  return 0;
}
