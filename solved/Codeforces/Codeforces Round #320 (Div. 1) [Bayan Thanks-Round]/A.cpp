// http://codeforces.com/contest/578/problem/A

using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-10;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x, y; cin >> x >> y;

  if (y > x) {
    cout << -1 << endl;
    return 0;
  }
  double num = x + y;

  long long lo = 1, hi = x + y;

  while (lo < hi) {
    if (lo + 1 == hi) {
      if (cmp(num / (2.0 * hi), y) != -1) {
        lo = hi;
      }
      break;
    }

    long long mid = (lo + hi) >> 1;
    if (cmp(num / (2.0 * mid), y) != -1) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  double best =  num / (2.0 * lo);
  cout << fixed << setprecision(10) << best << endl;

  return 0;
}