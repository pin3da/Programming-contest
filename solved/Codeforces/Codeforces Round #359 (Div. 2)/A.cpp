// http://codeforces.com/contest/686/problem/A

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, x;
  while (cin >> n >> x) {
    long long cur = x, ans = 0;
    for (int i = 0; i < n; ++i) {
      char op; long long d;
      cin >> op >> d;
      if (op == '+') {
        cur += d;
      } else {
        if (cur >= d) {
          cur -= d;
        } else {
          ans++;
        }
      }
    }
    cout << cur << ' ' << ans << endl;
  }

  return 0;
}
