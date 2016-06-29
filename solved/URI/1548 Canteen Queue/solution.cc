#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += (a[i].second == i);
    cout << ans << endl;
  }

  return 0;
}
