#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long double EPS = 1e-10;
int cmp(long double x, long double y = 0, long double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, a;
  cout << fixed << setprecision(4);

  while (cin >> n >> a && (n + a)) {
    vector<long long> d(n);
    for (auto &i : d) cin >> i;
    sort(d.rbegin(), d.rend());
    long long total = accumulate(d.begin(), d.end(), 0LL);
    if (a == total || a == 0)
      cout << ":D" << endl;
    else if (a > total)
      cout << "-.-" << endl;
    else {
      long double lo = 0, hi = d[0];
      while (cmp(lo, hi) == -1) {
        long double mid = (lo + hi) * 0.5;
        long double cur = 0;
        for (auto &i : d)
          if (i > mid) cur += i - mid;
          else break;

        if (cmp(a, cur) == 0) {
          lo = mid;
          break;
        }
        if (cmp(cur, a) == 1)
          lo = mid;
        else
          hi = mid;
      }
      cout << lo + EPS << endl;
    }
  }
  return 0;
}
