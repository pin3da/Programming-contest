#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      long long a = n - (i - 1);
      ans += a * a;
    }
    cout << ans << endl;
  }
  return 0;
}
