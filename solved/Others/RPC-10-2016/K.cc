#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

struct event {
  int x, y, l, t;
  event() {}
  event (int a, int b, int c, int d) :
    x(a), y(b), l(c), t(d) {}

  bool operator < (const event &o) const {
    if (x == o.x) {
      return t < o.t;
    }
    return x < o.x;
  }
};

const int MN = 300000 + 100;  // limit for array size

struct fenwick {
  int n;
  int t[MN + 10];

  void clear() {
    for (int i = 0; i < n; ++i) t[i] = 0;
  }

  void add(int i, long long p) { // add p at i
    for (i++; i <= n; i += i & -i)
      t[i] += p;
  }

  long long query(int i) {
    long long sum = t[0];
    for (i++; i > 0; i -= i & -i)
      sum += t[i];
    return sum;
  }

  long long query(int from, int to) {
    if (from) {
      return query(to) - query(from - 1);
    }
    return query(to);
  }
};

fenwick tree;
event ev[MN];
event sl[MN];

struct mapper {
  long long idy[MN];
  int len;
  void map_y(int slsize) {
    len = 0;
    for (int i = 0; i < slsize; ++i) {
      if (sl[i].t == 1) {
        idy[len++] = sl[i].y;
        idy[len++] = sl[i].y + sl[i].l;
      } else {
        idy[len++] = sl[i].y;
      }
    }
    sort(idy, idy + len);
    len = (unique(idy, idy + len) - idy);
  }

  int get(long long y) {
    int ans = conv(y);
    return ans;
  }
  int conv(long long y) { // returns a greater or equal value
    if (y > idy[len - 1]) return -1;
    return lower_bound(idy, idy + len, y) - idy;
  }

  int low(long long y) { // returns a lower or equal value
    if (y < idy[0]) return -1;
    int ans = lower_bound(idy, idy + len, y) - idy;
    if (idy[ans] > y) ans--;
    return ans;
  }
};

mapper realy;

int f(int slsize, int d) {
  int totev = 0;
  for (int i = 0; i < slsize; ++i) {
    if (2 * d > sl[i].l) continue;
    if (sl[i].t == 1) {
      ev[totev++] = event(sl[i].x, sl[i].y + d, sl[i].l - d - d, 1);
    } else {
      ev[totev++] = event(sl[i].x + d, sl[i].y, 0, 0);
      ev[totev++] = event(sl[i].x + sl[i].l - d, sl[i].y, 0, 2);
    }
  }

  sort(ev, ev + totev);
  tree.n = realy.len + 10;
  tree.clear();
  int front = 0, back = 0;
  long long ans = 0;
  for (int i = 0; i < totev; ++i) {
    if (ev[i].t == 0) tree.add(realy.get(ev[i].y), 1);
    else if (ev[i].t == 2) tree.add(realy.get(ev[i].y), -1);
    else {
      int top = ev[i].y + ev[i].l;
      int bottom = ev[i].y;
      int lo = realy.conv(bottom);
      int hi = realy.low(top);
      if (lo >= 0 && hi >= 0 && hi >= lo) {
        ans += tree.query(lo, hi);
      }
    }
  }
  return ans;
}



typedef unsigned int u32;
struct Reader {
  int b; Reader() { read(); }
  void read() { b = getchar_unlocked(); }
  void skip() { while (0 <= b && b <= 32) read(); }

  u32 next_u32() {
    u32 v=0; for (skip(); 48<=b&&b<=57; read()) v = 10*v+b-48; return v; }
  int next_int() {
    int v = 0; bool s = false;
    skip(); if (b == '-') { s = true; read(); }
    for (; 48<=b&&b<=57; read()) v = v*10 + b-48; return s ? -v : v; }
  char next_char() { skip(); char c = b; read(); return c; }
  void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }

  bool has_next() { skip(); return b > 0; }
  bool has_next_u32() { skip(); return 48 <= b && b <= 57; }
  bool has_next_int() { skip(); return b == 45 || (48 <= b && b <= 57); }
};

int main() {
  int n, m;
  Reader rd;
  while (rd.has_next()) {
    n = rd.next_int();
    m = rd.next_int();
    int len = 0;
    for (int i = 0; i < n; ++i) {
      int x, y, l;
      // cin >> x >> y >> l;
      x = rd.next_int();
      y = rd.next_int();
      l = rd.next_int();
      sl[len++] = (event(x, y, l, 1));
    }
    for (int i = 0; i < m; ++i) {
      int x, y, l;
      // cin >> x >> y >> l;
      x = rd.next_int();
      y = rd.next_int();
      l = rd.next_int();
      sl[len++] = (event(x, y, l, 0));
    }

    long long lo = 1, hi = 1000000000 + 1;
    realy.map_y(len);
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (f(len, mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    int ans = f(len, lo);
    if (ans) {
      cout << lo + lo << ' ' << ans << endl;
    } else {
      cout << 0 << ' ' << 0 << endl;
    }
  }
  return 0;
}
