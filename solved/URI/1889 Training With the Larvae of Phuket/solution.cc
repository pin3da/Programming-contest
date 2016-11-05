#include<bits/stdc++.h>
using namespace std;

const int MN = 2000 + 100;



typedef double ld;
pair<ld, int> a[MN];
const ld eps = 1e-15;
int cmp(ld x, ld y = 0, ld tol = eps){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ld heron(ld x, ld y, ld z) {
  ld r = (z + (x + y)) * (x - (z - y)) * (x + (z - y)) * (z + (y - x));
  return 0.25 * sqrt(r);
}

ld ans;int n;

void fun() {
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ld x = a[i].first, y = a[j].first;

      ld z = y - x;
      int id = lower_bound(a, a  + n, make_pair(z + eps, -1)) - a;
      while(id < n && (id == i || id == j || cmp((a[id].first + x), (y + eps)) != 1)) id++;
      if (id < j){
        ld rs = heron(x, y, a[id].first);
        assert(rs == rs);
        if(cmp(rs, eps) == 1)
          ans = min(ans, heron(x, y, a[id].first));
      }
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);

  ans = 1e100;
  fun();

  if (ans < 1e100)
    cout << ans << endl;
  else
    cout << -1 << endl;
}

int main() {
  int t; cin >> t;
  cout << fixed << setprecision(2);
  while (t--) {
    solve();
  }
  return 0;
}
