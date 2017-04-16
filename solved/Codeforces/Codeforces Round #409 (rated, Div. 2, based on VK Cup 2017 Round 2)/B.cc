#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string a, b;
  cin >> a >> b;
  string ans(a.size(), '0');
  int n = a.size();
  int ok = true;
  for (int i = 0; i < n && ok; ++i) {
    if (a[i] < b[i])
      ok = false;
    else
      ans[i] = min(a[i], b[i]);
  }
  if (ok)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
