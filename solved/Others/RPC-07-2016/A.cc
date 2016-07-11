#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double T;
struct ch {
  T v, t;
  ch() {}
  ch(T a, T b) : v(a), t(b) {}

  T get_dis(T t0) {
    return v * (t0 - t);
  }
};

const T EPS = 1e-9;
int cmp(T x, T y = 0, T tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

T fun(vector<ch> &all, T t0) {

  T mmin = 1e100, mmax = 0;
  for (auto &i : all) {
    mmin = min(mmin, i.get_dis(t0));
    mmax = max(mmax, i.get_dis(t0));
  }
  return  mmax - mmin;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cout << fixed << setprecision(10);
  while (cin >> n && n) {
    vector<ch> all(n);
    T tmax = 0;
    for (auto &i : all) {
      cin >> i.t >> i.v;
      tmax = max(tmax, i.t);
    }

    T lo = tmax, hi = tmax + 1e10;
    int maxiter = 1000000;
    while (hi - lo > EPS && maxiter > 0) {
      T delta = (hi - lo) / 3.0;
      T m1 = (2 * lo + hi) / 3.0, m2 = (lo + 2 * hi) / 3.0;
      T t1 = fun(all, m1);
      T t2 = fun(all, m2);
      if (cmp(m1, m2) == 1) break;
      if (cmp(t1, t2) != 1) {
        hi = m2;
      } else {
        lo = m1;
      }
      maxiter--;
    }
    cout << fun(all, (lo + hi) * 0.5) << endl;
  }

  return 0;
}
