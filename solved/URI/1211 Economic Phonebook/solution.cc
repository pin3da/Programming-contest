#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<string> g(n);
    for (auto &i : g) cin >> i;
    sort(g.begin(), g.end());
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        if (g[i][j] == g[i - 1][j]) ans++;
        else break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
