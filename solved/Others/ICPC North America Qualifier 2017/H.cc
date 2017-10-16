#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define name(x) cout << #x << endl

typedef long double T;

struct PT {
  T t, x, y;
  PT() {}
  PT(T _t, T _x, T _y) : t(_t), x(_x), y(_y) {}
};

T dist(PT a, PT b) {
  T dx = a.x - b.x;
  T dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}


void debug_route(vector<PT> &r) {
  cout << "--------" << endl;
  for (auto it : r) {
    cout << it.x << " " << it.y << " "  << it.t << endl;
  }
  cout << "--------" << endl;
}

T dist_route(vector<PT> &r) {
  T ans = 0;
  for (int i = 1; i < (int)r.size(); i++)
    ans += dist(r[i], r[i - 1]);
  return ans;
}

void debug_point(PT a) {
  cout << a.x << ' ' << a.y << ' ' << a.t << endl;
}

PT get_point(PT a, PT b, T t) {
  assert(a.t <= t && t <= b.t);
  T p = (t - a.t) / (b.t - a.t);
  PT ans(t, a.x + p * (b.x - a.x), a.y + p * (b.y - a.y));
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  long long n, t; cin >> n >> t;
  vector<PT> route(n);
  for (int i = 0; i < n; i++)
    cin >> route[i].x >> route[i].y >> route[i].t;
  vector<PT> gps;
  gps.push_back(route[0]);
  for (int i = 1; i < n - 1; i++) {
    PT prev = route[i - 1], curr = route[i], next = route[i + 1];
    long long lt = t * ((long long)(round(curr.t)) / t), rt = lt + t;
    if (prev.t <= lt && lt <= curr.t) {
      PT l = get_point(prev, curr, lt);
      if (gps.back().t < lt && route.back().t > lt) gps.push_back(l);
    }

    if (curr.t <= rt && rt <= next.t) {
      PT r = get_point(curr, next, rt);
      if (gps.back().t < rt && route.back().t > rt) gps.push_back(r);
    }
  }
  gps.push_back(route[n - 1]);
  T d1 = dist_route(route), d2 = dist_route(gps);
  // name(route);debug_route(route);
  // name(gps);debug_route(gps);
  // debug(d1);debug(d2);
  assert(d1 >= d2);
  cout << fixed << setprecision(8) << 100.0 * ((d1 - d2) / d1) << endl;
  return 0;
}
