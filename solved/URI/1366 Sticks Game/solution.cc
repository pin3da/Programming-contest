#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    long long ans = 0;
    long long accum = 0;
    while (n--) {
      int t, c;
      cin >> t >> c;
      ans += c / 4;
      c %= 4;
      if (c >= 2 && accum >= 2) {
        ans++;
        c = 0;
        accum -= 2;
      } else if (c >= 2) {
          accum += min(2, c);
      }
    }
    ans += accum / 4;
    cout << ans << endl;
  }
  return 0;
}
