#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl
int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string a, b;
  cin >> a >> b;
  int k; cin >> k;

  if (k >= int(a.size() + b.size())) {
    puts("Yes");
  } else {
    int j = 0;
    int t = min(a.size(), b.size());
    for (; j < t && a[j] == b[j]; ++j);
    int len = a.size() - j + b.size() - j;
    if (len <= k) {
      if (((k - len) & 1) == 0) {
        puts("Yes");
      } else {
        puts("No");
      }
    } else {
        puts("No");
    }
  }
  return 0;
}
