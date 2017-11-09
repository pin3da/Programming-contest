#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, r, k;
  while (cin >> n >> r >> k) {
    int b = n - r;
    int mmin = r - min(r, k) + max(0, k - r);
    int mmax = b - min(b, k) + max(0, k - b);
    cout << mmin << ' ' << n - mmax << endl;
  }
  return 0;
}
