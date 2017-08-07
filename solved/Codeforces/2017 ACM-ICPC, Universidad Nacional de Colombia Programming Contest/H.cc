#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  char ans[n][n << 1 | 1];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < (n << 1 | 1); j++)
      ans[i][j] = ' ';

  for (int i = 0; i < n; i++) {
    ans[i][0] = '*';
    ans[i][n - 1] = '*';
    ans[i][n + 1] = '*';
    ans[i][n << 1] = '*';
    ans[n - 1][i] = '*';
    ans[0][n + 1 + i] = '*';
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n << 1 | 1); j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
