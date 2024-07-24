#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k != 0) {
      ans++;
      k -= n;
      n--;
      while (k > 0) {
        ans++;
        k -= n;
        if (k <= 0) {
          break;
        }
        ans++;
        k -= n;
        n--;
      }
    }
    assert(k <= 0);
    cout << ans << endl;
  }
  return 0;
}