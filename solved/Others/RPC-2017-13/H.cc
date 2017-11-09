#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n;

  while (cin >> n) {
    vector<int> all(n);
    for (auto &i : all) {
      cin >> i;
      i--;
    }
    vector<int> inv(n);
    for (int i = 0; i < n; i++) {
      inv[all[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (all[i] == i) continue;
      int j = inv[i];
      swap(all[i], all[j]);
      swap(inv[all[i]], inv[all[j]]);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
