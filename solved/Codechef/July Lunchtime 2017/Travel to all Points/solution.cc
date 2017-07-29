#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct point {
  int x, y;
  point() {}
  point(int a, int b) : x(a), y(b) {}
  bool operator < (const point &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};

long long dis(point &a, point &b) {
  return 0LL + llabs(a.x - b.x) + llabs(a.y - b.y);
}

int find_set(vector<int> &p, int x) {
  return p[x] == x ? x : p[x] = find_set(p, p[x]);
}

void join(vector<int> &p, int i, int j) {
  p[find_set(p, i)] = find_set(p, j);
}

bool test(vector<point> &a, long long d) {
  vector<int> p(a.size());
  for (int i = 0; i < (int)p.size(); i++)
    p[i] = i;
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (dis(a[i], a[j]) >= d)
        join(p, i, j);
    }
  }
  set<int> roots;
  for (int i = 0; i < (int)a.size(); i++) {
    roots.insert(find_set(p, i));
  }
  return roots.size() == 1;
}

const long long inf = 2000000001LL;

void solve() {
  int n; cin >> n;
  vector<point> all(n);
  for (auto &i: all) {
    cin >> i.x >> i.y;
  }

  sort(all.begin(), all.end());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dis(all[i], all[j]) << " ";
    }
    cout << endl;
  }

  long long lo = 0, hi = inf;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (test(all, mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
