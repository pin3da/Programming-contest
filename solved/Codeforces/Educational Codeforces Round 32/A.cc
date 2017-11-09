#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if ((a[i] > a[i - 1] && a[i] > a[i + 1]) ||(a[i] < a[i - 1] && a[i] < a[i + 1]) )
      ans++;
  }
  cout << ans << endl;
  return 0;
}
