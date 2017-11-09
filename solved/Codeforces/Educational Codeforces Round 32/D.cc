#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1001;
long long comb[MN][MN];


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  comb[0][0] = 1;
  for (int i = 1; i < MN; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) comb[i][j] = 1;
      else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
  }

  long long n, k;
  cin >> n >> k;
  long long ans = 1;
  if (k == 2) {
    ans = (n * (n - 1)) / 2 + 1;
  }

  if (k == 3) {
    ans = 1 + comb[n][2] + 2 * comb[n][3];
  }

  if (k == 4) {
    ans = 1  + comb[n][2] + 2 * comb[n][3] + 9 * comb[n][4];
  }

  cout << ans << endl;

  return 0;
}
