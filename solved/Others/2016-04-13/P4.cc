#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long double t;
  cout << fixed << setprecision(6);
  while (cin >> t && (t > 0)) {
    long double i = ((t - 3.0) * 2.0) + 3.0;
    cout << (i - t) / t << endl;
  }
  return 0;
}
