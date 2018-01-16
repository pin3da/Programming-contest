#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


const double pi = acos(-1);
struct poly {
  deque<double> coef;
  double x_lo, x_hi;

  void init(int n) {
    for (int i = 0; i < n + 1; i++) {
      double t; cin >> t;
      coef.push_front(t);
    }
    cin >> x_lo >> x_hi;
  }

  double evaluate(double x) {
    double ans = 0;
    for (auto it : coef)
      ans = (ans * x + it);
    return ans;
  }

  double volume(double x, double dx=1e-6) {
    dx = (x_hi - x_lo) / 1000000.0;
    double ans = 0;
    for (double ix = x_lo; ix <= x; ix += dx) {
      double rad = evaluate(ix);
      ans += pi * rad * rad * dx;
    }
    return ans;
  }
};

void solve(int n) {
  poly bottle;
  bottle.init(n);
  double delta;
  cin >> delta;


  double vol = bottle.volume(bottle.x_hi);
  cout << vol << endl;

  if (vol < delta) {
    cout << "insufficient volume" << endl;
  } else {
    int iter = 8;
    double last_x = bottle.x_lo;
    const double dx = (bottle.x_hi - bottle.x_lo) / 1000000.0;
    while (iter-- > 0 && cmp(last_x, bottle.x_hi) == -1) {
      double cur_vol = 0;
      for (; cur_vol <= delta; last_x += dx) {
        double rad = bottle.evaluate(last_x);
        cur_vol += pi * rad * rad * dx;
      }
      if (cmp(last_x, bottle.x_hi) == -1) {
        if (iter != 7) cout << " ";
        cout << last_x - bottle.x_lo;
      }
    }
    cout << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cout << fixed << setprecision(2);

  int tc_id = 0;
  while (cin >> n)  {
    cout << "Case " << (++tc_id) << ": ";
    solve(n);
  }

  return 0;
}
