#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 1000000 + 1;
vector<int> mex[MN];
int gn[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for (int i = 2; i < MN; ++i) {
    if (mex[i].size()) {
      sort(mex[i].begin(), mex[i].end());
      mex[i].resize(
          unique(mex[i].begin(), mex[i].end()) - mex[i].begin());

      int seen = false;
      for (int j = 0; j < mex[i].size(); ++j) {
        if (mex[i][j] > j + 1) {
          gn[i] = j;
          seen = true;
          break;
        }
      }
      if (!seen)
        gn[i] = mex[i].size() + 1;
    } else {
      gn[i] = 1;
    }

    for (int j = i + i; j < MN; j += i) {
      mex[j].push_back(gn[i]);
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
