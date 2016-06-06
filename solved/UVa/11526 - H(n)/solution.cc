#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    long long n; cin >> n;
    int k = sqrt(n);
    long long ans = 0;
    for (int i = 1; i <= k; ++i)
      ans += n / i + n / i;
    ans -= k * k;
    cout << ans << endl;
  }

  return 0;
}
