#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 100000 + 1;
int gn[MN];
int mex[500];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  for (int i = 2; i < MN; ++i) {
    memset(mex, 0, sizeof mex);
    for (int j = 1; j * j <= i; ++j) {
      if ((i % j) == 0) {
        int y = i / j;
        int z = j;
        if (y != 1) {
          if (y & 1)
            mex[gn[z]] = true;
          else
            mex[0] = true;
        }

        if (j > 1) {
          z = i / j;
          if (j & 1)
            mex[gn[z]] = true;
          else
            mex[0] = true;
        }
      }
    }
    for (int j = 0; j < 500; ++j)
      if (!mex[j]) {
        gn[i] = j;
        break;
      }
  }

  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int t; cin >> t;
      ans ^= gn[t];
    }
    puts(ans ? "1" : "2");
  }
  return 0;
}
