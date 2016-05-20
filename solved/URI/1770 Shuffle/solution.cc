#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> d(n), p(m);
    for (auto &i : d) cin >> i;
    for (auto &i : p) cin >> i;
    if (m < n) {
      cout << -1 << endl;
      continue;
    }

    set<int> seen;
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
      ans += d[p[i] - 1];
      seen.insert(p[i] - 1);
      if (seen.size() == n)
        break;
    }
    if (seen.size() == n) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
