#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


const long double EPS = 1e-9;
int cmp(long double x, long double y = 0, long double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct line {
  long double m, b;
  line(long double x, long double y) : m(x), b(y) {}
  long double find_p(long double x) {
    return max<long double>(0.0, (m * x - b));
  }
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n, p;
  cin >> n >> p;
  vector<pair<int, int>> all(n);
  vector<line> zero;
  for (auto &i : all) {
    cin >> i.first >> i.second;
    zero.push_back(line(i.first, i.second));
  }

  long double lo = 0, hi = 1e19;
  int max_iter = 128;
  while ((max_iter--) && (cmp(lo, hi) == -1)) {
    long double mid = (lo + hi) * 0.5;
    long double need = 0;
    for (auto &i : zero)
      need += i.find_p(mid);
    if (cmp(need, p * mid) == -1) {
      lo = mid;
    } else if (cmp(need, p * mid) == 1) {
      hi = mid;
    } else {
      break;
    }
  }
  if (lo < 1e18) {
    cout << fixed << setprecision(10);
    cout << lo << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
