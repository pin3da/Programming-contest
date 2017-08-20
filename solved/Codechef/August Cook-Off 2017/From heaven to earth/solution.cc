#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

double s2 = sqrt(2);

void solve() {
  double n, v1, v2;
  cin >> n >> v1 >> v2;
  double t1 = n * s2 / v1;
  double t2 = n * 2.0 / v2;
  puts(t1 < t2 ? "Stairs" : "Elevator");
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
