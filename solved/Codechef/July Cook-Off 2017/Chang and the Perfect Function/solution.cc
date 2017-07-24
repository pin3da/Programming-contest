#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1000000 + 100;
long long sq[MN];


void solve() {
  long long a, b; cin >> a >> b;
  long long ans = 0;

  long long top = a * a + b;

  for (int i = 0; sq[i] <= top; i++) {
    int lo = 0, hi = min<int>(i - 1, a - 1);
    int upper = hi;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (sq[i] - sq[mid] <= b) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (sq[i] - sq[lo] > b) continue;
    if (upper >= lo)
      ans += upper - lo + 1;
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  for (long long i = 1; i < MN + 1; ++i) {
    sq[i - 1] = i * i;
  }

  solve();
  return 0;
}
