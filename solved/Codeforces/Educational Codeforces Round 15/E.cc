#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 100000 + 100;
const int MK = 35; // Log (10 ** 10)

int to[MN];
long long w[MN];

int dpt[MN][MK];
long long dpw[MN][MK];
long long dpm[MN][MK];

int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, q; cin >> n >> q;
  for (int i = 0; i < n; ++i)
    cin >> dpt[i][0];
  for (int i = 0; i < n; ++i) {
    cin >> dpw[i][0];
    dpm[i][0] = dpw[i][0];
  }

  for (int k = 1; k < MK; ++k) {
    for (int i = 0; i < n; ++i) {
      dpt[i][k] = dpt[dpt[i][k - 1]][k - 1];
      int to = dpt[i][k - 1];
      dpw[i][k] = dpw[i][k - 1] + dpw[dpt[i][k - 1]][k - 1];
      dpm[i][k] = min(dpm[i][k - 1], dpm[dpt[i][k - 1]][k - 1]);
    }
  }

  for (int i = 0; i < n; ++i) {
    int cur = i;
    long long sum = 0;
    long long mmin = 1000LL * 1000LL * 1000LL * 1000LL;
    for (int k = MK - 1; k >= 0; --k) {
      if ((q >> k) & 1) {
        sum += dpw[cur][k];
        mmin = min(mmin, dpm[cur][k]);
        cur = dpt[cur][k];
      }
    }
    cout << sum << ' ' << mmin << endl;
  }

  return 0;
}
