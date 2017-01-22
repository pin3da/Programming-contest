#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int m, d;
  cin >> m >> d;
  m--;
  d--;
  int t = days[m];
  int ans = 0;
  while (t--) {
    d++;
    if (d == 7) {
      if (t) ans++;
      d = 0;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
