#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  long long m;

  while (cin >> n >> m && (n > 0 && m > 0)) {
    long long ans = 0;
    long long acc = 0;
    for (int i = 0; i < n; ++i) {
      int t; cin >> t;
      acc += t;
      ans += (acc * m);
    }
    cout << ans << endl;
  }
  return 0;
}
