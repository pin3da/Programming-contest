#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> id(n), val(n);

  vector<pair<int, int>> tmp;
  for (int i = 0; i < n; ++i) {
    int t; cin >> t;
    tmp.emplace_back(t, i);
  }

  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < n; ++i) {
    val[tmp[i].second] = i;
  }

  for (int i = 0; i < n; ++i) {
    id[val[i]] = i;
  }
  long long ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    int dist = min((abs(id[i] - id[i + 1])), n - abs(id[i] - id[i + 1]));
    ans += dist;
  }
  cout << ans << endl;
  return 0;
}
