using namespace std;
#include <bits/stdc++.h>

bool d(int n, int t) {
  return (n % t) == 0;
}

bool check(int n, int m, int t) {
  int ok = 0;
  if (d(n, t) && d(m - 1, t) && d(n - 1, t) && d(m - 2, t))
    ok = true;
  if (d(n, t) && d(m - 1, t) && d(n - 2, t) && d(m - 1, t))
    ok = true;
  if (d(n, t) && d(m - 2, t) && d(n - 1, t) && d(m - 1, t))
    ok = true;
  if (d(n, t) && d(m - 2, t) && d(n    , t) && d(m - 2, t))
    ok = true;
  if (d(n - 1, t) && d(m, t) && d(n - 1, t) && d(m - 2, t))
    ok = true;
  if (d(n - 1, t) && d(m, t) && d(n - 2, t) && d(m - 1, t))
    ok = true;
  if (d(n - 1, t) && d(m - 1, t) && d(n, t) && d(m - 2, t))
    ok = true;
  if (d(n - 1, t) && d(m - 1, t) && d(n - 1, t) && d(m - 1, t))
    ok = true;
  return ok;
}

int main() {
  long long n, m;
  while (cin >> n >> m) {
    int q; cin >> q;
    while (q--) {
      long long t; cin >> t;
      int ok = check(n, m, t) || check(m, n, t);
      if (ok)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
