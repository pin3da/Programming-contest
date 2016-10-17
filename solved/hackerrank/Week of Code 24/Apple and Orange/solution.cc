#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int s, t;
  while (cin >> s >> t) {
    int a, b; cin >> a >> b;
    int n, m; cin >> n >> m;
    int ans[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
      int d; cin >> d;
      if (a + d >= s && a + d <= t) ans[0]++;
    }
    for (int i = 0; i < m; ++i) {
      int d; cin >> d;
      if (b + d >= s && b + d <= t) ans[1]++;
    }
    cout << ans[0] << endl;
    cout << ans[1] << endl;
  }
  return 0;
}
