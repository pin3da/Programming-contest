#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, q, tc = 0;
  while (cin >> n >> q && (n + q)) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> inv(10000 + 10, -1);
    for (int i = n - 1; i >= 0; --i)
      inv[a[i]] = i + 1;
    cout << "CASE# " << ++tc << ":" << endl;
    while (q--) {
      int t; cin >> t;
      if (inv[t] == -1)
        cout << t << " not found" << endl;
      else
        cout << t << " found at " << inv[t] << endl;
    }
  }

  return 0;
}
