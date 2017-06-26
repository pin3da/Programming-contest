#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n;
  cin >> n;
  vector<pair<long long, int>> ans(4);
  for (int i = 0; i < 4; ++i) ans[i].second = -i;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    ans[i & 3].first += t;
  }

  sort(ans.rbegin(), ans.rend());
  cout << char('A' - ans[0].second) << endl;
  return 0;
}
