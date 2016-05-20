#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long double eps = 1e-9;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long double a, b, c;
  cout << fixed << setprecision(3);
  while (cin >> a >> b >> c) {
    vector<long double> t = {a, b, c};
    sort(t.rbegin(), t.rend());
    if (t[0] + eps >= t[1] + t[2])
      cout << -1.0 << endl;
    else {
      long double s = (a + b + c) * 0.5;
      long double ans = 4.0 / 3.0 * sqrt(s * (s - a) * (s - b) * (s - c));
      cout << ans + eps << endl;
    }

  }
  return 0;
}
