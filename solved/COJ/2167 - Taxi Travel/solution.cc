#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<int> a(5);
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      a[t]++;
    }

    int ans = a[4];
    int cur = min(a[1], a[3]);
    ans += cur;
    a[1] -= cur;
    a[3] -= cur;

    ans += a[3];
    ans += a[2] / 2;
    a[2] %= 2;
    if (a[2]) {
      a[1] -= 2;
      ans++;
    }
    if (a[1] > 0)
    ans += (a[1] + 3)/ 4;
    cout << ans << endl;
  }
  return 0;
}
