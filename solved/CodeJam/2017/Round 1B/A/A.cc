#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-10;
int cmp(ld x, ld y = 0, ld tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct horse{
   ld x, s;
   horse() {}
   ld find_x(ld speed) {
     if (cmp(speed, s) != 1) return 1e100;
     return (x / (speed - s)) * speed;

   }
};

ld min_cross(vector<horse> &a, ld speed) {
  ld ans = 1e100;
  for (auto i : a) {
    ans = min(ans, i.find_x(speed));
  }
  return ans;
}

void solve() {
  int n;
  ld d;
  cin >> d >> n;
  vector<horse> all(n);
  for (auto &i: all)
    cin >> i.x >> i.s;

  ld lo = 0, hi = 1e17;
  int max_iter = 1000;
  while ((max_iter--) && cmp(lo, hi) == -1) {
    ld mid = (lo + hi) * 0.5;
    if (min_cross(all, mid) >= d) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  printf("%.10lf\n", (double)(lo));
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
