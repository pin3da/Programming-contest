#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 10010;
int gy[MN];
int mex[MN];

int main() {
  ios_base::sync_with_stdio(false);
  gy[1] = 1;
  gy[2] = 2;
  gy[3] = 3;
  for (int i = 4; i < MN; ++i) {
    memset(mex, 0, sizeof mex);
    for (int k = 1; k < 4; ++k) {
      for (int j = k - 1; j + k < i; ++j) {
        int cur = gy[j - k + 1] ^ gy[i - j - 1];
        mex[cur] = 1;
      }
    }
    for (int j = 0; j < MN; ++j) {
      if (!mex[j]) {
        gy[i] = j;
        break;
      }
    }
  }
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    int ans = 0, t;
    while (n--) {
      cin >> t;
      ans ^= gy[t];
    }
    puts(ans == 0 ? "SLAVKO" : "MIRKO");
  }
  return 0;
}
