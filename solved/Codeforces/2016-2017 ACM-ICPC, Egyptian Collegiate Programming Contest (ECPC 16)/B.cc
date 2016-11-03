#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl


typedef long double ld;

const ld eps = 1e-12;
int cmp(ld x, ld y = 0, ld tol = eps) {
  return ( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  ld x, y;
  point(ld a, ld b) : x(a), y(b) {}
  point() {}
  point(const point &p) : x(p.x), y(p.y)    {}
  point operator + (const point &p)  const { return point(x+p.x, y+p.y); }
  point operator - (const point &p)  const { return point(x-p.x, y-p.y); }
  point operator * (double c)     const { return point(x*c,   y*c  ); }
  point operator / (double c)     const { return point(x/c,   y/c  ); }
};

struct rect {
  ld x1, x2, y1, y2;
  point edges[4];
  rect(ld a, ld b, ld c, ld d) {
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = d;
    edges[0] = point(x1, y1);
    edges[1] = point(x2, y1);
    edges[2] = point(x2, y2);
    edges[3] = point(x1, y2);
  }
};

ld dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}

ld dist2(point a, point b) {
  point p = a - b;
  return dot(p, p);
}


point proj_seg(point a, point b, point c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < eps) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

// compute distance from c to segment between a and b
ld point_seg(point a, point b, point c) {
  return sqrt(dist2(c, proj_seg(a, b, c)));
}


ld fun(rect &s1, rect &s2) {
  ld ans = 1e100;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int k = (j + 1) % 4;
      ans = min(ans,
          point_seg(s2.edges[j], s2.edges[k], s1.edges[i]));
    }
  }
  return ans;
}

ld min_dist(rect &s1, rect &s2) {
  return min(fun(s1, s2), fun(s2, s1));
}

ld dist[123];

struct st {
  int node;
  ld dist;
  st () {}
  st (int a, ld d) : node(a), dist(d) {}
  bool operator < (const st &o) const {
    if (dist == o.dist) return node < o.node;
    return dist > o.dist;
  }
};

ld dijkstra(vector<rect> &g, int s, int tar) {
  for (int i = 0; i < (int)g.size(); ++i) dist[i] = 1e100;
  dist[s] = 0;

  priority_queue<st> q;
  q.push(st(s, 0));

  while (!q.empty()) {
    st cur = q.top(); q.pop();
    if (cur.dist > dist[cur.node]) continue;
    for (int i = 0; i < (int)g.size(); ++i) {
      if (i == cur.node) continue;
      ld w_extra = min_dist(g[cur.node], g[i]);
      if (dist[cur.node] + w_extra < dist[i]) {
        dist[i] = dist[cur.node] + w_extra;
        q.push(st(i, dist[i]));
      }
    }
  }
  return dist[tar];
}

void solve() {
  int n;
  long long l, u;
  scanf("%d%lld%lld", &n, &l, &u);

  vector<rect> s;
  s.push_back(rect(0, 0, u, -10));
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (d == 0) {
      int x1 = 0, x2 = b, y1 = c + a, y2 = c;
      s.push_back(rect(x1, y1, x2, y2));
    } else {
      int x1 = u - b, x2 = u, y1 = c + a, y2 = c;
      s.push_back(rect(x1, y1, x2, y2));
    }
  }
  s.push_back(rect(0, l + 10, u, l));

  printf("%.10lf\n", (double)dijkstra(s, 0, s.size() - 1));
}

int main() {
#ifndef LOCAL
  freopen("street.in", "r", stdin);
#endif

  int t; scanf("%d", &t);
  while(t--) solve();

  return 0;
}
