#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long mat[60];
    memset(mat, 0, sizeof mat);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = 0; j < 32; ++j) {
        if ((a[i] >> j) & 1)
          mat[j] |= (1LL << i);
      }
    }

    long long best = 0;
    long long p = (1LL << n) - 1;
    for (int i = 32; i >= 0; --i) {
      if (__builtin_popcount(p & mat[i]) >= k) {
        best |= (1LL << i);
        p &= mat[i];
      }
    }
    cout << best << endl;
  }
  return 0;
}
