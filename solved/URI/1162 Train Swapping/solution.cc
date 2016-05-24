#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), frec(n + 1);
    for (auto &i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = a[i]; j <= n; ++j)
        ans += frec[j];
      frec[a[i]]++;
    }
    cout << "Optimal train swapping takes " << ans << " swaps." << endl;
  }
  return 0;
}
