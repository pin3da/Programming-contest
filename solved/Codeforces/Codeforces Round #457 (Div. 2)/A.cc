#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

bool has_7(int x) {
  while (x > 0) {
    if ((x % 10) == 7) return true;
    x /= 10;
  }
  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int x;
  int h, m;
  cin >> x >> h >> m;

  int cur = h * 60 + m;
  int ans = 0;
  while (true) {
    int hh = cur / 60;
    int mm = cur % 60;
    if (has_7(hh) || has_7(mm))
      break;
    cur -= x;
    if (cur < 0) {
      cur += 24 * 60;
    }
    ans++;
  }

  cout << ans << endl;
  return 0;
}
