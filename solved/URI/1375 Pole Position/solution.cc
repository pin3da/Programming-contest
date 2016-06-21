#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> p(n), a(n);
    for (int i = 0; i < n; ++i)
      cin >> p[i] >> a[i];

    vector<int> ans(n, -1);
    int ok = true;
    for (int i = 0; i < n && ok; ++i) {
      if (a[i] + i >= n || a[i] + i < 0)
        ok = false;
      else if (ans[i + a[i]] != -1)
        ok = false;
      else
        ans[i + a[i]] = p[i];
    }

    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
