#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

inline int fun(int k, int i) {
  if ((i % k) == 0) return 0;
  return i;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n, k; cin >> n >> k;
    long long ans = 0;
    for (int i = 1; i * i <= n; ++i) {
      if ((n % i) == 0) {
        ans += fun(k, i);
        if ((n / i) != i) {
          ans += fun(k, n / i);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
