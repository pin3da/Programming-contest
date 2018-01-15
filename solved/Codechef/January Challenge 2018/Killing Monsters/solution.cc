#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  vector<int> data(n);
  for (auto &i : data) cin >> i;
  int q; cin >> q;
  int alive = n;
  while (q--) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i >= 0; i = (i - 1) & x) {
      if (i < n) {
        if (data[i] > 0 && data[i] <= y) {
          data[i] = 0;
          alive--;
        } else if (data[i] > y) {
          data[i] -= y;
        }
      }
      if (i == 0) break;
    }
    cout << alive << endl;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
