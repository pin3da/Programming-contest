#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const double EPS = 1e-15;
int cmp(double x, double y = 0, double tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool can(vector<double> &a, vector<double> &b, double f, double p) {
  int n = a.size();
  p += f;
  double l = p / a[0];
  if (cmp(l, f) == 1) return false;

  f -= l;
  p -= l;

  for (int i = 1; i < n; i++) {
    l = p / b[i];
    if (cmp(l, f) == 1) return false;
    f -= l;
    p -= l;

    l = p / a[i];
    if (cmp(l, f) == 1) return false;
    f -= l;
    p -= l;
  }

  l = p / b[0];
  if (cmp(l, f) == 1) return false;
  f -= l;
  p -= l;

  return true;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n; cin >> n;
  double payload; cin >> payload;

  vector<double> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  double lo = 0, hi = 1e9;
  if (!can(a, b, hi, payload)) {
    cout << -1 << endl;
    return 0;
  }

  int max_iter = 30000;

  while ((cmp(lo, hi, 1e-10) == -1) && (max_iter--) > 0) {
    double mid = (lo + hi) * 0.5;
    if (can(a, b, mid, payload)) hi = mid;
    else lo = mid;
  }
  cout << fixed << setprecision(12) << lo << endl;
  return 0;
}
