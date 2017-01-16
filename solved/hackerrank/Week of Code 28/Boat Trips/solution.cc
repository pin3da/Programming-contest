#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, c, m;
  cin >> n >> c >> m;
  int ok = true;
  for (int i = 0; i < n; ++i) {
    int p; cin >> p;
    int need = (p + c - 1) / c;
    if (need > m) ok = false;
  }
  puts(ok ? "Yes" : "No");
  return 0;
}
