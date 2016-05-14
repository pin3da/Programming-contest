#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int cool = true, t;
      for (int j = 0; j < m; ++j) {
        cin >> t;
        cool &= t > 0;
      }
      ans += cool;
    }
    cout << ans << endl;
  }
  return 0;
}
