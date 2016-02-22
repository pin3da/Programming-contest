#include <iostream>
#include <vector>
#define D(x) cout << #x " = " << (x) << endl
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int t = 1 << n;
    long long best = 0;
    int len = 0;
    for (int mask = 1; mask < t; ++mask) {
      long long aand = (1LL << 62) - 1, xxor = 0;
      for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
          aand = aand & a[i];
          xxor = xxor ^ a[i];
        }
      }
      long long cur = aand | xxor;
      if (cur == best) {
        len = max(len, __builtin_popcount(mask));
      } else if (cur > best) {
        best = cur;
        len = __builtin_popcount(mask);
      }
    }
    cout << best << " " << len << endl;

  }
  return 0;
}
