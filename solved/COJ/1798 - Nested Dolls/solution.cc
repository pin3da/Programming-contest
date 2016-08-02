#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

struct point {
  int x, y;
  point() {}
  point(int a, int b) : x(a), y(b) {}
  bool operator <(const point &o) const {
    if (x == o.x) return y > o.y;
    return x < o.x;
  }
};


deque<point> border(deque<point> &q) {
  point cur(0, 0);
  deque<point> ans;
  for (auto &p : q) {
    if (p.x <= cur.x || p.y <= cur.y) {
      ans.push_back(p);
    } else {
      cur = p;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    deque<point> a(n);
    for (auto &i: a) cin >> i.x >> i.y;
    sort(a.begin(), a.end());

    int ans = 0;
    while (a.size()) {
      a = border(a);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
