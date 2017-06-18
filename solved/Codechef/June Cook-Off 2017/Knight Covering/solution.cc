// Wrong Answer!
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int best2(int m) {
  if (m == 0) return 0;
  if (m == 1) return 2;
  else return 4;
}

int best3(int m) {
  if (m == 0) return 0;
  if (m == 1) return 2;
  return 4;
}

void solve() {
  int n, m; cin >> n >> m;
  if (m < n) swap(n, m);
  if (n == 1) {
    cout << m << endl;
  }
  if (n == 2) {
    int t = m / 6;
    int r = m % 6;
    cout << t * 4 + best2(r) << endl;
  }
  if (n == 3) {
    if (m <= 6) cout << 4 << endl;
    else {
      int t = m / 6;
      int r = m % 6;
      cout << t * 4 + best3(r) << endl;
    }
  }

}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  while(tc--) solve();
  return 0;
}
