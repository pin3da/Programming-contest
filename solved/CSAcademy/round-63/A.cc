#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  int ans = 0;

  for (int i = 0; i <= m - n; i++) {
    int ok = true;
    for (int j = 0; j < n && ok; j++) {
      ok &= (a[j] + b[i + j]) == 1;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
