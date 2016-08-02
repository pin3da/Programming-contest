#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl



int main() {
  ios_base::sync_with_stdio(false);
  int tc; cin >> tc;
  cout << fixed << setprecision(1);
  while (tc--) {
    long double a, b, c;
    cin >> a >> b >> c;
    long double s = (a + b + c) * 0.5;
    long double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << area * 7.0 << endl;
  }
  return 0;
}
