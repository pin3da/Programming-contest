#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int S = 20000;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int h = 0;
  int n; cin >> n;
  int ok = true;
  while (n--) {
    int d;
    string m;
    cin >> d >> m;
    if (h == 0) {
      ok &= (m == "South");
    }
    if (h == S) {
      ok &= (m == "North");
    }
    if (m == "South") {
      h += d;
    }
    if (m == "North") {
      h -= d;
    }
    ok &= ((h >= 0) && (h <= S));
  }
  ok &= (h == 0);
  puts(ok ? "YES" : "NO");

  return 0;
}
