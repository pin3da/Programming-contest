#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; ++i)
      a[i][i] = 2, a[i][n - 1 - i] = 3;


    int k = n / 3;
    int kk = 2 * n / 3;
    if ((n % 3) == 0) {
      kk--;
    }
    for (int i = k; i <= kk; ++i) {
      for (int j = k; j <= kk; ++j)
        a[i][j] = 1;
    }

    a[n / 2][n / 2] = 4;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cout << a[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
