#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, q;
  while (cin >> n >> q) {
    vector<int> all(n);
    for (int &i : all) cin >> i;
    sort(all.rbegin(), all.rend());
    while (q--) {
      int t; cin >> t;
      cout << all[t - 1] << endl;
    }
  }
  return 0;
}
