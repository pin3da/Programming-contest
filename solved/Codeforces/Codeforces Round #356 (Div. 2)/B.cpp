// http://codeforces.com/contest/680/problem/B

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, a;
  while (cin >> n >> a) {
    vector<int> p(n), d(n), t(n);
    for (auto &i : p) cin >> i;
    a--;
    for (int i = a + 1; i < n; ++i) {
      d[i - a] += p[i];
      t[i - a]++;
    }
    for (int i = a - 1; i >= 0; --i) {
      d[a - i] += p[i];
      t[a - i]++;
    }
    int ans = p[a];
    for (int i = 0; i < n; ++i) {
      if (d[i] == t[i] && t[i]) {
        ans += d[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
