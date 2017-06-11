#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 512;

int g[MN][MN];

void solve() {
  int n;  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }
  long long ans = 0;
  vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  reverse(input.begin(), input.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int a = input[j], b = input[k], c = input[i];
        g[a][b] = min(g[a][b], g[a][c] + g[c][b]);
      }
    }
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= i; ++k) {
        int a = input[j], b = input[k];
        ans += g[a][b];
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
