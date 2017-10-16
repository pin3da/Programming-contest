#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k, m;
  cin >> n >> k >> m;
  vector<long long> a(n);
  vector<vector<long long>> ans(m);
  for (auto &i: a) {
    cin >> i;
    ans[i % m].push_back(i);
  }

  int seen = false;
  for (int i = 0; !seen && i < m; i++) {
    if ((int) ans[i].size() >= k) {
      cout << "Yes" << endl;
      for (int j = 0; j < k; j++) {
        if (j) cout << " ";
        cout << ans[i][j];
      }
      cout << endl;
      seen = true;
    }
  }
  if (!seen)
    cout << "No" << endl;

  return 0;
}
