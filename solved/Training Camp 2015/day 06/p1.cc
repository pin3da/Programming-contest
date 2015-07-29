using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int> > g(r, vector<int> (c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> g[i][j];
    }
  }

  int ans = 0;
  for (int j = 0; j < c; ++j) {
    int fixed = r - 1;
    for (int i = r - 1; i >= 0; --i) {
      if (g[i][j] == 1) {
        ans += (fixed - i);
        fixed--;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
