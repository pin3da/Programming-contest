#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long double EPS = 1e-15;
int cmp(long double x, long double y = 0, long double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

long double my_atan2(long double y, long double x) {
  long double ans = atan2(y, x);
  if (ans < 0) ans += 2.0 * acos(-1);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<long double> d(n + 1), a(n + 1), b(n + 1);

  for (int i = 0; i < n + 1; ++i) {
    cin >> d[i] >> a[i] >> b[i];
  }

  long double max_p = my_atan2(b[n], d[n]);
  long double min_p = my_atan2(a[n], d[n]);

  long double upper = my_atan2(b[0], d[0]);
  long double lower = my_atan2(a[0], d[0]);
  for (int i = 0; i < n; ++i) {
    upper = min(upper, my_atan2(b[i], d[i]));
    lower = max(lower, my_atan2(a[i], d[i]));
  }

  int ok = (cmp(upper, min_p) != -1 && cmp(lower, max_p) != 1 && cmp(lower, upper) != 1);
  if (ok)
    cout << "Y" << endl;
  else
    cout << "N" << endl;
  return 0;
}

