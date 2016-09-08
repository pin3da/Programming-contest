#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

int side = 1;
int flip(int n, int cur, int rot) {
  int c = cur - rot;
  int mod = 2 * n;
  int ans = (rot - c) % mod;
  return (ans + mod ) % mod;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
    int mod = 2 * n;
    side = 1;
    long long rot = 0;
    int cur = 0;
    while (m--) {
      int op, t;
      cin >> op >> t;
      if (op == 1) cur = ((cur + 2 * t) + mod) % mod;
      else {
        cur = flip(n, cur, t);
        side *= -1;
      }
    }
    if (side > 0) {
      int ans = ((mod - cur) / 2) % n;
      cout << "1 " << ans << endl;
    } else {
      int seen = false;
      for (int i = 0; i < n; ++i) {
        if (flip(n, cur, i) == 0) {
          cout << "2 " << i << endl;
          seen = true;
          break;
        }
      }
      assert(seen);
    }
  }
  return 0;
}
