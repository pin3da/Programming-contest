#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    long long ant; cin >> ant;
    long long ans = 100;
    for (int i = 1; i < n; ++i) {
      long long cur;
      cin >> cur;
      if (cur > ant)
        ans += min<long long>(100000, ans / ant) * (cur - ant);
      ant = cur;
    }
    cout << ans << endl;
  }
  return 0;
}
