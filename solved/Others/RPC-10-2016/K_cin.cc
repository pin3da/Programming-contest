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
  void print() {
    for (int i = 0; i < len; ++i) {
      cout << idy[i] << " = " << i << endl;
    }
    cout << endl;
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
      // cout << " at " << x << endl;
      // debug(hi); debug(lo);
      // cout << endl;
      if (lo >= 0 && hi >= 0 && hi >= lo) {
        ans += tree.query(lo, hi);
      }
    }
  }
  return ans;
}

void debug_events(vector<event> &sl) {
  cout << " === " << endl;
  for (int i = 0; i < sl.size(); ++i) {
    cout << sl[i].x << " " << sl[i].y
      << " " << sl[i].t << " " << sl[i].l << endl;
  }
  cout << " === " << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    int len = 0;
    for (int i = 0; i < n; ++i) {
      int x, y, l;
      cin >> x >> y >> l;
      sl[len++] = (event(x, y, l, 1));
    }
    for (int i = 0; i < m; ++i) {
      int x, y, l;
      cin >> x >> y >> l;
      sl[len++] = (event(x, y, l, 0));
    }
    // sort(sl.begin(), sl.end());
    // debug_events(sl);

    long long lo = 1, hi = 1000000000 + 1;
    realy.map_y(len);
    // realy.print();
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
