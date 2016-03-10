#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<vector<int>> a(n, vector<int>(n, 3));
    for (int i = 0; i < n; ++i) {
      a[i][i] = 1;
      a[i][n - i - 1] = 2;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
