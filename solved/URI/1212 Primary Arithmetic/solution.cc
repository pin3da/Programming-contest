#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b && (a + b)) {
    int c = 0, ans = 0;
    while (a > 0 || b > 0) {
      ans += c;
      int x = a % 10, y = b % 10;
      c = (x + y + c) / 10;
      a /= 10;
      b /= 10;
    }
    ans += c;
    if (ans == 0)
      cout << "No carry operation." << endl;
    else if (ans > 1)
      cout << ans << " carry operations." << endl;
    else
      cout << ans << " carry operation." << endl;
  }
  return 0;
}
