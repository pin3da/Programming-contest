#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<vector<int>> a(2);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[t & 1].push_back(t);
  }

  long long ans = 0;
  for (int i = 0; i < (int)a[0].size(); ++i) ans += a[0][i];
  sort(a[1].rbegin(), a[1].rend());
  int tmp = a[1].size() & 1;
  int t = a[1].size() - tmp;
  for (int i = 0; i < t; ++i) ans += a[1][i];
  cout << ans << endl;
  return 0;
}
