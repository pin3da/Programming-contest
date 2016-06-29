#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, d;
  while (cin >> n >> d && (n + d)) {
    string line; cin >> line;
    vector<vector<int>> last(n + 1, vector<int>(11));
    for (int i = 0; i < 11; ++i) last[n][i] = n;
    for (int i = n - 1; i >= 0; --i) {
      int cur = line[i] - '0';
      for (int j = 0; j < 11; ++j)
        last[i][j] = n;

      last[i][cur] = i;
      for (int j = 0; j < 11; ++j)
        last[i][j] = min(last[i][j], last[i + 1][j]);
    }

    int q = n - d;
    for (int i = 0; i < n; ++i) {
      int cur = line[i] - '0', best = n;
      for (int j = cur + 1; j < 11; ++j)
        best = min(best, last[i + 1][j]);

      if (n - best < q) {
        cout << line[i];
        q--;
      }
    }
    assert(q == 0);
    cout << endl;
  }
  return 0;
}
