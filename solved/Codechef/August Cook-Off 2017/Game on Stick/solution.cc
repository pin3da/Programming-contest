#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  long long n; cin >> n;
  long long x1, y1, x2, y2;
  cin >> y1 >> x1 >> y2 >> x2;
  x1--;x2--;
  long long target = n >> 1;
  long long d1 = llabs(x1 - target);
  long long d2 = llabs(x2 - target);
  if (x1 == x2) {
    cout << "Draw" << endl;
    return;
  }
  if (n & 1) {
    if (d1 < d2) {
      cout << "Miron" << endl;
    } else if (d2 < d1){
      cout << "Slava" << endl;
    } else {
      if (y1 == y2) {
        cout << "Miron" << endl;
      } else {
        cout << "Draw" << endl;
      }
    }
  } else {
    d1 = max(llabs(x1 - target), llabs(x1 - (target - 1)));
    d2 = max(llabs(x2 - target), llabs(x2 - (target - 1)));
    if (d1 < d2) {
      cout << "Miron" << endl;
    } else if (d2 < d1){
      cout << "Slava" << endl;
    } else {
      cout << "Draw" << endl;
    }
  }
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
