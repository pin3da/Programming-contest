#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long r, n;
  int tc = 0;
  while (cin >> r >> n && (n + r)) {
    cout << "Case " << ++tc << ": ";
    if (r > n * 27)
      cout << "impossible" << endl;
    else
      cout << ((r + n - 1) / n) - 1 << endl;
  }
  return 0;
}
